//
// Created by Gennadiy Sosnov on 03.10.2022.
//

#include "TitleBar.h"

TitleBar::TitleBar(QWidget* parent)
    : QWidget(parent)
{
    setObjectName("titleBar");
    setFixedHeight(TITLE_HEIGHT);
    setAttribute(Qt::WA_StyledBackground);

    maximizeIcon = QPixmap(":/resources/icons/maximize_black.png");
    restoreIcon = QPixmap(":/resources/icons/restore_black.png");
    closeIcon = QPixmap(":/resources/icons/close_black.png");
    closeHoverIcon = QPixmap(":/resources/icons/close_white.png");

    mainLayout = new QHBoxLayout(this);

    buttonsWidget = new QWidget(this);

    buttonsLayout = new QHBoxLayout(buttonsWidget);
    buttonsLayout->setAlignment(Qt::AlignVCenter);
    buttonsLayout->setSpacing(0);
    buttonsLayout->setContentsMargins(0, 0, 0, 0);

    spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    minimizeButton = new CustomButton(this);
    minimizeButton->setFlat(true);
    minimizeButton->setFixedSize(SYS_BUTTON_WIDTH, SYS_BUTTONS_HEIGHT);
    minimizeButton->setObjectName("minimizeButton");
    minimizeButton->setIcon(QPixmap(":/resources/icons/minimize_black.png"));
    minimizeButton->setCursor(QCursor(Qt::PointingHandCursor));
    connect(minimizeButton, &QPushButton::clicked, this->window(), &QWidget::showMinimized);

    maximizeButton = new CustomButton(this);
    maximizeButton->setFlat(true);
    maximizeButton->setFixedSize(SYS_BUTTON_WIDTH, SYS_BUTTONS_HEIGHT);
    maximizeButton->setObjectName("maximizeButton");
    maximizeButton->setIcon(QPixmap(":/resources/icons/maximize_black.png"));
    maximizeButton->setCursor(QCursor(Qt::PointingHandCursor));
    connect(maximizeButton, &QPushButton::clicked, this, &TitleBar::toggleMaxState);

    closeButton = new CustomButton(this);
    closeButton->setFlat(true);
    closeButton->setFixedSize(SYS_BUTTON_WIDTH, SYS_BUTTONS_HEIGHT);
    closeButton->setObjectName("closeButton");
    closeButton->setIcon(QPixmap(":/resources/icons/close_black.png"));
    closeButton->setCursor(QCursor(Qt::PointingHandCursor));
    connect(closeButton, &QPushButton::clicked, this->window(), &QWidget::close);

    buttonsLayout->addWidget(minimizeButton);
    buttonsLayout->addWidget(maximizeButton);
    buttonsLayout->addWidget(closeButton);

    mainLayout->addItem(spacer);
    mainLayout->addWidget(buttonsWidget);

    mainLayout->setSpacing(3);
    mainLayout->setContentsMargins(3, 0, 0, 0);

    _isMaximized = false;

    connect(closeButton, &CustomButton::hovered, this, &TitleBar::setCloseButton);
}

TitleBar::~TitleBar() = default;

void TitleBar::mouseDoubleClickEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
        toggleMaxState();
}

void TitleBar::mousePressEvent(QMouseEvent* event)
{
    ReleaseCapture();
    SendMessage((HWND)window()->winId(), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
    event->ignore();
}

void TitleBar::toggleMaxState()
{
    if (window()->isMaximized())
    {
        window()->showNormal();
    }
    else
    {
        window()->showMaximized();
    }
}

void TitleBar::toggleMaximizeButton(bool isMaximized)
{
    _isMaximized = isMaximized;
    updateMaximizeButton();
}

void TitleBar::updateMaximizeButton()
{
    if (_isMaximized) {
        maximizeButton->setIcon(restoreIcon);
        return;
    }
    maximizeButton->setIcon(maximizeIcon);
}

void TitleBar::setCloseButton(bool isHovered)
{
    if (isHovered)
    {
        closeButton->setIcon(closeHoverIcon);
        return;
    }
    closeButton->setIcon(closeIcon);
}
