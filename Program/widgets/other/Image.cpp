//
// Created by Gennadiy Sosnov on 17.10.2022.
//

#include "Image.h"

Image::Image(QWidget *parent) : QWidget{parent}
{

}

void Image::setPixmap(const QPixmap& pix)
{
    loadedImage = pix;
}

QPixmap Image::getPixmap() const
{
    return loadedImage;
}
