//
// Created by Student on 17.10.2022.
//

#ifndef SRC_IMAGE_H
#define SRC_IMAGE_H

#include <QWidget>

class Image : public QWidget{
    Q_OBJECT

    QPixmap* loadedImage = nullptr;

public:
    explicit Image(QWidget* parent = Q_NULLPTR);

    void setPixmap(QPixmap* pix);

    QPixmap* getPixmap() const;
};


#endif //SRC_IMAGE_H