//
// Created by Gennadiy Sosnov on 18.10.2022.
//

#include "DarkLightTitleBar.h"

DarkLightTitleBar::DarkLightTitleBar(QWidget *parent) : SimpleTitleBar{parent}
{
    changeModeButton = new CustomButton(buttonsWidget);
    changeModeButton->setFlat(true);
    changeModeButton->setFixedSize(SYS_BUTTON_WIDTH, SYS_BUTTONS_HEIGHT);
    changeModeButton->setObjectName("changeModeButton");
    changeModeButton->setIcon(QPixmap(":/resources/icons/moon.png"));
    changeModeButton->setCursor(QCursor(Qt::PointingHandCursor));
    changeModeButton->setToolTip("Switch to dark mode");
    connect(changeModeButton, &QPushButton::clicked, this, &DarkLightTitleBar::toggleMode);

    isLight = true;

    buttonsLayout->insertWidget(0, changeModeButton);
}

DarkLightTitleBar::~DarkLightTitleBar() = default;

void DarkLightTitleBar::toggleMode()
{
    isLight = !isLight;
    emit ModeChanged(isLight);
    if (isLight)
    {
        maximizeIcon = QPixmap(":/resources/icons/maximize_black.png");
        restoreIcon = QPixmap(":/resources/icons/restore_black.png");
        closeIcon = QPixmap(":/resources/icons/close_black.png");

        minimizeButton->setIcon(QPixmap(":/resources/icons/minimize_black.png"));
        closeButton->setIcon(QPixmap(":/resources/icons/close_black.png"));
        changeModeButton->setIcon(QPixmap(":/resources/icons/moon.png"));
        changeModeButton->setToolTip("Switch to dark mode");

        updateMaximizeButton();

        return;
    }
    maximizeIcon = QPixmap(":/resources/icons/maximize_white.png");
    restoreIcon = QPixmap(":/resources/icons/restore_white.png");
    closeIcon = QPixmap(":/resources/icons/close_white.png");

    minimizeButton->setIcon(QPixmap(":/resources/icons/minimize_white.png"));
    closeButton->setIcon(QPixmap(":/resources/icons/close_white.png"));
    changeModeButton->setIcon(QPixmap(":/resources/icons/sun.png"));
    changeModeButton->setToolTip("Switch to light mode");

    updateMaximizeButton();
}
