//
// Created by Gennadiy Sosnov on 17.10.2022.
//

#ifndef POLYTECH_IMAGE_H
#define POLYTECH_IMAGE_H

#include <QWidget>

class Image : public QWidget{
    Q_OBJECT

    QPixmap loadedImage;

public:
    explicit Image(QWidget* parent = Q_NULLPTR);

    void setPixmap(const QPixmap& pix);

    QPixmap getPixmap() const;
};


#endif //POLYTECH_IMAGE_H
