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

    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    welcome = new WelcomeContainer(this);

    workArea = new WorkArea(this);
    workArea->hide();

    mainLayout->addWidget(welcome);
    mainLayout->addWidget(workArea);
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
