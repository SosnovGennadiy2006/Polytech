//
// Created by Student on 17.10.2022.
//

#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow{parent}
{
    setupUI();
}

void MainWindow::setupUI()
{
    setStyleSheet(StyleSheetsHelper::loadStyles(":/resources/styles/main.qss"));
}
