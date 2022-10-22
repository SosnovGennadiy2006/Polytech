//
// Created by genas on 03.10.2022.
//

#include "FramelessWindow.h"

FramelessWindow::FramelessWindow(QWidget* parent)
    : QWidget(parent)
{
    memset(&monitorInfo, 0, sizeof(MONITORINFO));
    monitorInfo.cbSize = sizeof(MONITORINFO);

    layout = new QVBoxLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);

    titleBar = new TitleBar(this);
    titleBar->setObjectName("titleBar");

    mainWidget = new QWidget(this);
    mainWidget->setObjectName("mainWidget");
    mainWidget->setAttribute(Qt::WA_StyledBackground);
    mainWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout->addWidget(titleBar);
    layout->addWidget(mainWidget, 1);

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint);

    WindowEffect::addWindowAnimation((HWND)winId());
    WindowEffect::addShadowEffect((HWND)winId());

    connect(windowHandle(), &QWindow::screenChanged, this, [=] {
        auto hWnd = reinterpret_cast<HWND>(windowHandle()->winId());
        SetWindowPos(hWnd, NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);
    });
}

void FramelessWindow::setTitleBar(TitleBar *_titleBar)
{
    layout->removeWidget(titleBar);
    delete titleBar;
    titleBar = _titleBar;
    titleBar->setParent(this);
    layout->insertWidget(0, titleBar);
}

bool FramelessWindow::nativeEvent(const QByteArray& eventType, void* message, qintptr* result)
{
    MSG* msg = reinterpret_cast<MSG*>(message);
    if (msg->message == WM_NCHITTEST)
    {
        int xPos = (LOWORD(msg->lParam) - frameGeometry().x()) % 65536;
        int yPos = HIWORD(msg->lParam) - frameGeometry().y();
        int w = width();
        int h = height();
        bool lx = xPos < BORDER_WIDTH;
        bool rx = xPos > w - BORDER_WIDTH;
        bool ty = yPos < BORDER_WIDTH;
        bool by = yPos > h - BORDER_WIDTH;

        if (lx && ty)
        {
            *result = HTTOPLEFT;
            return true;
        }
        else if (rx && by)
        {
            *result = HTBOTTOMRIGHT;
            return true;
        }
        else if (rx && ty) {
            *result = HTTOPRIGHT;
            return true;
        }
        else if (lx && by) {
            *result = HTBOTTOMLEFT;
            return true;
        }
        else if (ty) {
            *result = HTTOP;
            return true;
        }
        else if (by) {
            *result = HTBOTTOM;
            return true;
        }
        else if (lx) {
            *result = HTLEFT;
            return true;
        }
        else if (rx) {
            *result = HTRIGHT;
            return true;
        }
    }
    else if (msg->message == WM_NCCALCSIZE)
    {
        if (isWindowMaximized(msg->hwnd))
        {
            monitorNCCALCSIZE(msg);
        }

        *result = HTNOWHERE;
        return true;
    }
    else if (msg->message == WM_GETMINMAXINFO)
    {
        if (isWindowMaximized(msg->hwnd))
        {
            RECT window_rect;
            if (!GetWindowRect(msg->hwnd, &window_rect))
            {
                *result = HTNOWHERE;
                return false;
            }

            HMONITOR hMonitor = MonitorFromRect(&window_rect, MONITOR_DEFAULTTONULL);
            if (!hMonitor)
            {
                *result = HTNOWHERE;
                return false;
            }

            GetMonitorInfoW(hMonitor, &monitorInfo);
            RECT monitor_rect = monitorInfo.rcMonitor;
            RECT work_area = monitorInfo.rcWork;

            LPMINMAXINFO info = reinterpret_cast<LPMINMAXINFO>(msg->lParam);

            info->ptMaxSize.x = work_area.right - work_area.left;
            info->ptMaxSize.y = work_area.bottom - work_area.top;
            info->ptMaxTrackSize.x = info->ptMaxSize.x;
            info->ptMaxTrackSize.y = info->ptMaxSize.y;

            info->ptMaxPosition.x = abs(window_rect.left - monitor_rect.left);
            info->ptMaxPosition.y = abs(window_rect.top - monitor_rect.top);
            *result = HTCLIENT;
            return true;
        }
    }

    return QWidget::nativeEvent(eventType, message, result);
}

void FramelessWindow::changeEvent(QEvent* event)
{
    if (event->type() == QEvent::WindowStateChange)
    {
        titleBar->toggleMaximizeButton(isMaximized());
    }

    return QWidget::changeEvent(event);
}

bool FramelessWindow::isWindowMaximized(HWND hWnd)
{
    WINDOWPLACEMENT wp;
    wp.length = sizeof(WINDOWPLACEMENT);
    GetWindowPlacement(hWnd, &wp);
    return wp.showCmd == SW_MAXIMIZE;
}

void FramelessWindow::monitorNCCALCSIZE(MSG* msg)
{
    HMONITOR hMonitor = MonitorFromWindow(msg->hwnd, MONITOR_DEFAULTTONULL);
    if (hMonitor != NULL)
    {
        GetMonitorInfoW(hMonitor, &monitorInfo);
    }

    NCCALCSIZE_PARAMS& params = *reinterpret_cast<NCCALCSIZE_PARAMS*>(msg->lParam);
    params.rgrc[0].left = monitorInfo.rcWork.left;
    params.rgrc[0].top = monitorInfo.rcWork.top;
    params.rgrc[0].right = monitorInfo.rcWork.right;
    params.rgrc[0].bottom = monitorInfo.rcWork.bottom;
}
