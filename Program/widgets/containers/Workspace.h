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
#include "../../widgets/buttons/StyledButton.h"
#include "../../widgets/other/Image.h"
#include "WelcomeContainer.h"

class StyledButton;

class Workspace : public QWidget{
    Q_OBJECT

    QVBoxLayout* mainLayout;

    WelcomeContainer* welcome;

    QWidget* imageWidget;
    QHBoxLayout* imageLayout;
    Image* mainImage;

    QWidget* optionsWidget;
    QHBoxLayout* optionsLayout;
    StyledButton* enterImageButton;
    StyledButton* addCircleButton;

    QWidget* infoWidget;
    QGridLayout* infoGrid;

    QLabel* lbl1;
    QLabel* lbl2;
    QLabel* lbl3;

    QLabel* info1;
    QLabel* info2;
    QLabel* info3;

    QSpacerItem* spacer;
    QSpacerItem* vSpacer;

public:
    explicit Workspace(QWidget* parent = Q_NULLPTR);

    void setupUI();

public slots:
    void setIsLight(bool isLight);
};


#endif//POLYTECH_WORKSPACE_H
