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
    setWindowIcon(QIcon(":/resources/icons/icon.png"));
    setWindowTitle("Main window");
    setStyleSheet(StyleSheetsHelper::mergeStyles({
            ":/resources/styles/main.qss",
            ":/resources/styles/light.qss"
    }));

    setMinimumSize(700, 500);

    mainLayout = new QVBoxLayout(mainWidget);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    workspace = new Workspace(mainWidget);
    workspace->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    mainLayout->addWidget(workspace);
}

void MainWindow::setupConnections()
{
    connect(titleBar, &DarkLightTitleBar::ModeChanged, this, &MainWindow::changeMode);
}

void MainWindow::changeMode(bool isLight)
{
    workspace->setIsLight(isLight);
    if (isLight)
    {
        setStyleSheet(StyleSheetsHelper::mergeStyles({
                ":/resources/styles/main.qss",
                ":/resources/styles/light.qss"
        }));
        update();
        return;
    }
    setStyleSheet(StyleSheetsHelper::mergeStyles({
            ":/resources/styles/main.qss",
            ":/resources/styles/dark.qss"
    }));
    update();
}
