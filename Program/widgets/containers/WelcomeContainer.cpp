//
// Created by Student on 24.10.2022.
//

#include "WelcomeContainer.h"

WelcomeContainer::WelcomeContainer(QWidget* parent) : QWidget{parent}
{
    setAttribute(Qt::WA_StyledBackground);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setObjectName("welcomeWidget");

    hSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    vSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    QFont bigFont;
    bigFont.setPixelSize(42);
    bigFont.setFamily("Calibri");
    QFont ordinaryFont;
    ordinaryFont.setPixelSize(32);
    ordinaryFont.setFamily("Calibri");
    QFont smallFont;
    smallFont.setPixelSize(28);
    smallFont.setFamily("Calibri");

    mainLayout = new QVBoxLayout(this);

    widget1 = new QWidget(this);

    layout1 = new QHBoxLayout(widget1);
    layout1->setContentsMargins(0, 0, 0, 0);

    welcomeLabel1 = new QLabel(widget1);
    welcomeLabel1->setText("Welcome to the App!");
    welcomeLabel1->setObjectName("welcomeLabel1");
    welcomeLabel1->setFont(bigFont);

    layout1->addItem(hSpacer);
    layout1->addWidget(welcomeLabel1);
    layout1->addItem(hSpacer);

    widget2 = new QWidget(this);
    layout2->setContentsMargins(0, 0, 0, 0);

    layout2 = new QHBoxLayout(widget2);

    welcomeLabel2 = new QLabel(widget2);
    welcomeLabel2->setText("This application can count the "
                           "<span style='color: #0a95ff'>maximum</span>, "
                           "<span style='color: #0a95ff'>minimum</span>, "
                           "<span style='color: #0a95ff'>average</span> "
                           "brightness of pixels on an X-ray image, for this:");
    welcomeLabel2->setAlignment(Qt::AlignCenter);
    welcomeLabel2->setFont(ordinaryFont);
    welcomeLabel2->setObjectName("welcomeLabel2");
    welcomeLabel2->setMinimumWidth(600);
    welcomeLabel2->setWordWrap(true);

    widget3 = new QWidget(this);
    layout3 = new QHBoxLayout(widget3);
    openImageButton = new StyledButton(widget3);
    openImageButton->setText("Open image");
    openImageButton->setFont(smallFont);
    openImageButton->setObjectName("colorButton");
    openImageButton->setMinimumWidth(100);

    layout3->addItem(hSpacer);
    layout3->addWidget(openImageButton);
    layout3->addItem(hSpacer);

    layout2->addItem(hSpacer);
    layout2->addWidget(welcomeLabel2);
    layout2->addItem(hSpacer);

    mainLayout->addItem(vSpacer);
    mainLayout->addWidget(widget1);
    mainLayout->addWidget(widget2);
    mainLayout->addWidget(widget3);
    mainLayout->addItem(vSpacer);
}

void WelcomeContainer::setIsLight(bool isLight)
{
    if (isLight)
    {
        welcomeLabel2->setText("This application can count the "
                               "<span style='color: #0a95ff'>maximum</span>, "
                               "<span style='color: #0a95ff'>minimum</span>, "
                               "<span style='color: #0a95ff'>average</span> "
                               "brightness of pixels on an X-ray image, for this:");
        return;
    }
    welcomeLabel2->setText("This application can count the "
                           "<span style='color: #f48225'>maximum</span>, "
                           "<span style='color: #f48225'>minimum</span>, "
                           "<span style='color: #f48225'>average</span> "
                           "brightness of pixels on an X-ray image, for this:");
}
