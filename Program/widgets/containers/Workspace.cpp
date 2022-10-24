//
// Created by Student on 20.10.2022.
//

#include "Workspace.h"

Workspace::Workspace(QWidget* parent) : QWidget{parent}
{
    setupUI();
}

void Workspace::setupUI()
{
    setAttribute(Qt::WA_StyledBackground);
    setObjectName("workspace");

    spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    vSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    welcome = new WelcomeContainer(this);

    imageWidget = new QWidget(this);
    imageWidget->hide();

    imageLayout = new QHBoxLayout(imageWidget);

    mainImage = new Image(imageWidget);

    imageLayout->addItem(spacer);
    imageLayout->addWidget(mainImage);
    imageLayout->addItem(spacer);

    optionsWidget = new QWidget(this);
    optionsWidget->hide();

    optionsLayout = new QHBoxLayout(optionsWidget);
    optionsLayout->setSpacing(5);

    enterImageButton = new StyledButton(optionsWidget);
    enterImageButton->setText("Enter image");

    addCircleButton = new StyledButton(optionsWidget);
    addCircleButton->setText("select circle");

    optionsLayout->addItem(spacer);
    optionsLayout->addWidget(enterImageButton);
    optionsLayout->addWidget(addCircleButton);

    infoWidget = new QWidget(this);
    infoWidget->hide();

    infoGrid = new QGridLayout(infoWidget);

    lbl1 = new QLabel(infoWidget);
    lbl1->setObjectName("tableInfoName");
    lbl1->setText("Minimum intensity:");

    lbl2 = new QLabel(infoWidget);
    lbl2->setObjectName("tableInfoName");
    lbl2->setText("Average intensity:");

    lbl3 = new QLabel(infoWidget);
    lbl3->setObjectName("tableInfoName");
    lbl3->setText("Maximum intensity:");

    info1 = new QLabel(infoWidget);
    info1->setObjectName("tableInfo");
    info1->setText("");

    info2 = new QLabel(infoWidget);
    info2->setObjectName("tableInfo");
    info2->setText("");

    info3 = new QLabel(infoWidget);
    info3->setObjectName("tableInfo");
    info3->setText("");

    infoGrid->addWidget(lbl1, 0, 0);
    infoGrid->addWidget(lbl2, 1, 0);
    infoGrid->addWidget(lbl3, 2, 0);
    infoGrid->addItem(spacer, 0, 1);
    infoGrid->addItem(spacer, 1, 1);
    infoGrid->addItem(spacer, 2, 1);
    infoGrid->addWidget(info1, 0, 2);
    infoGrid->addWidget(info2, 1, 2);
    infoGrid->addWidget(info3, 2, 2);

    mainLayout->addWidget(welcome);
    mainLayout->addWidget(imageWidget);
    mainLayout->addWidget(optionsWidget);
    mainLayout->addWidget(infoWidget);
}

void Workspace::setIsLight(bool isLight)
{
    welcome->setIsLight(isLight);
}
