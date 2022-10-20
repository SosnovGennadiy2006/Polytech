//
// Created by genas on 03.10.2022.
//

#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : DarkLightWindow{parent}
{
    setStyleSheet(StyleSheetsHelper::loadStyles(":/Program/styles/main.qss"));
}