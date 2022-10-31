//
// Created by Gennadiy Sosnov on 17.10.2022.
//

#include "Image.h"

Image::Image(QWidget *parent) : QWidget{parent}
{
    mainLayout = new QHBoxLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    hSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    view = new QLabel(this);
    view->setObjectName("imageView");
    view->setStyleSheet("background: red;");

    mainLayout->addItem(hSpacer);
    mainLayout->addWidget(view);
    mainLayout->addItem(hSpacer);
}

void Image::setPixmap(const QPixmap& pix)
{
    loadedImage = pix;
    view->setPixmap(pix);
}

QPixmap Image::getPixmap() const
{
    return loadedImage;
}
