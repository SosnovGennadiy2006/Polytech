//
// Created by Student on 20.10.2022.
//

#ifndef POLYTECH_WORKSPACE_H
#define POLYTECH_WORKSPACE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSpacerItem>
#include <QLabel>
#include "../../widgets/buttons/CustomButton.h"
#include "../../widgets/other/Image.h"

class Workspace : public QWidget{
    Q_OBJECT

    QVBoxLayout* mainLayout;

    QWidget* imageWidget;
    QHBoxLayout* imageLayout;
    Image* mainImage;

    QWidget* optionsWidget;
    QHBoxLayout* optionsLayout;
    QSpacerItem* spacer;
    CustomButton* enterImageButton;
    CustomButton* addCircleButton;

    QWidget* infoWidget;
    QGridLayout* infoGrid;

    QLabel* lbl1;
    QLabel* lbl2;
    QLabel* lbl3;

    QLabel* info1;
    QLabel* info2;
    QLabel* info3;

public:
    explicit Workspace(QWidget* parent = Q_NULLPTR);

    void setupUI();
};


#endif//POLYTECH_WORKSPACE_H
