//
// Created by Gennadiy Sosnov on 03.10.2022.
//

#ifndef POLYTECH_FRAMELESSWINDOW_H
#define POLYTECH_FRAMELESSWINDOW_H

#include <QWidget>
#include <windows.h>
#include <QWindow>
#include "../../widgets/titleBars/TitleBar.h"
#include "../../widgets/other/WindowEffect.h"

class FramelessWindow : public QWidget {
    Q_OBJECT

public:
    explicit FramelessWindow(QWidget* parent = Q_NULLPTR);

    void setTitleBar(TitleBar* _titleBar);

protected:
    bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;
    void changeEvent(QEvent* event) override;

    TitleBar* titleBar;
    QWidget* mainWidget;

private:
    bool isWindowMaximized(HWND hWnd);
    void monitorNCCALCSIZE(MSG* msg);

    QVBoxLayout* layout;

    MONITORINFO monitorInfo;
    RECT monitorRect;
    RECT workArea;
};

#endif//POLYTECH_FRAMELESSWINDOW_H
