//
// Created by genas on 03.10.2022.
//

#ifndef POLYTECH_TITLEBAR_H
#define POLYTECH_TITLEBAR_H

#include <QWidget>
#include <QToolButton>
#include <QPushButton>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QLabel>
#include <windows.h>
#include "../../widgets/other/TitleBarProperties.h"
#include "../../widgets/buttons/CustomButton.h"

class TitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit TitleBar(QWidget *parent = Q_NULLPTR);
    ~TitleBar() override;

    void toggleMaximizeButton(bool isMaximized);
    void updateMaximizeButton();
protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;

    QHBoxLayout* mainLayout;
    QWidget* buttonsWidget;
    QHBoxLayout* buttonsLayout;
    QSpacerItem* spacer;
private:
    void toggleMaxState();

    bool _isMaximized;

protected:
    CustomButton* minimizeButton;
    CustomButton* maximizeButton;
    CustomButton* closeButton;

    QPixmap maximizeIcon;
    QPixmap restoreIcon;
};

#endif//POLYTECH_TITLEBAR_H
