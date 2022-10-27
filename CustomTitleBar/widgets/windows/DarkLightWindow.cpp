//
// Created by Gennadiy Sosnov on 18.10.2022.
//

#include "DarkLightWindow.h"

DarkLightWindow::DarkLightWindow(QWidget *parent) : FramelessWindow{parent}
{
    titleBar = new DarkLightTitleBar(this);

    setTitleBar(titleBar);
}
