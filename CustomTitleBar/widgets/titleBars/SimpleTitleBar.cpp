//
// Created by Gennadiy Sosnov on 03.10.2022.
//

#include "SimpleTitleBar.h"

SimpleTitleBar::SimpleTitleBar(QWidget *parent) : TitleBar{parent}
{
    logoLabel = new QLabel(this);
    logoLabel->setObjectName("logoLabel");

    titleLabel = new QLabel(this);
    titleLabel->setObjectName("titleLabel");
    titleLabel->setText("Window Title");

    mainLayout->insertWidget(0, titleLabel, 1);
    mainLayout->insertWidget(0, logoLabel);

    connect(this->window(), &QWidget::windowTitleChanged, titleLabel, &QLabel::setText);
    connect(this->window(), &QWidget::windowIconChanged, this, [this](const QIcon& icon){
        logoLabel->setPixmap(icon.pixmap(24, 24));
    });
}

SimpleTitleBar::~SimpleTitleBar()
{

}
