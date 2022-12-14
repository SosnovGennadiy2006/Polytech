//
// Created by Gennadiy Sosnov on 17.10.2022.
//

#ifndef POLYTECH_IMAGE_H
#define POLYTECH_IMAGE_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QSpacerItem>

class Image : public QWidget{
    Q_OBJECT

    QPixmap loadedImage;
    QLabel* view;

    QHBoxLayout* mainLayout;
    QSpacerItem* hSpacer;

public:
    explicit Image(QWidget* parent = Q_NULLPTR);

    void setPixmap(const QPixmap& pix);

    QPixmap getPixmap() const;
};


#endif //POLYTECH_IMAGE_H
