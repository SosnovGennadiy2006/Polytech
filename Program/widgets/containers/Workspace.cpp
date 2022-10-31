//
// Created by Gennadiy Sosnov on 20.10.2022.
//

#include "Workspace.h"

Workspace::Workspace(QWidget* parent) : QWidget{parent}
{
    setupUI();

    connect(welcome, &WelcomeContainer::openImageButtonClicked, this, &Workspace::openImage);
}

void Workspace::setupUI()
{
    setAttribute(Qt::WA_StyledBackground);
    setObjectName("workspace");

    hSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    welcomeWrapper = new QWidget(this);
    welcomeWrapper->setObjectName("welcomeWrapper");

    welcomeLayout = new QHBoxLayout(welcomeWrapper);
    welcomeLayout->setSpacing(0);
    welcomeLayout->setContentsMargins(0, 0, 0, 0);

    welcome = new WelcomeContainer(welcomeWrapper);

    welcomeLayout->addItem(hSpacer);
    welcomeLayout->addWidget(welcome);
    welcomeLayout->addItem(hSpacer);

    workAreaWrapper = new QWidget(this);
    workAreaWrapper->setObjectName("workAreaWrapper");

    workAreaLayout = new QHBoxLayout(workAreaWrapper);
    workAreaLayout->setSpacing(0);
    workAreaLayout->setContentsMargins(0, 0, 0, 0);

    workArea = new WorkArea(this);
    workArea->hide();

    workAreaLayout->addItem(hSpacer);
    workAreaLayout->addWidget(workArea);
    workAreaLayout->addItem(hSpacer);

    mainLayout->addWidget(welcomeWrapper);
    mainLayout->addWidget(workAreaWrapper);
}

void Workspace::setIsLight(bool isLight)
{
    welcome->setIsLight(isLight);
}

void Workspace::openImage()
{
    workArea->openImage();
    welcome->hide();
    workArea->show();
}
