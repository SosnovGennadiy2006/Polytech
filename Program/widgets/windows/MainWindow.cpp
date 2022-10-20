//
// Created by genas on 03.10.2022.
//

#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) : DarkLightWindow{parent}
{
    setupUI();
    setupConnections();
}

void MainWindow::setupUI()
{
    setWindowIcon(QIcon(":/Program/resources/icons/icon.png"));
    setStyleSheet(StyleSheetsHelper::mergeStyles({
            ":/Program/resources/styles/main.qss",
            ":/Program/resources/styles/light.qss"
    }));

    setMinimumSize(700, 500);
}

void MainWindow::setupConnections()
{
    connect(titleBar, &DarkLightTitleBar::ModeChanged, this, &MainWindow::changeMode);
}

void MainWindow::changeMode(bool isLight)
{
    if (isLight)
    {
        setStyleSheet(StyleSheetsHelper::mergeStyles({
                ":/Program/resources/styles/main.qss",
                ":/Program/resources/styles/light.qss"
        }));
        update();
        return;
    }
    setStyleSheet(StyleSheetsHelper::mergeStyles({
            ":/Program/resources/styles/main.qss",
            ":/Program/resources/styles/dark.qss"
    }));
    update();
}
