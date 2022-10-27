//
// Created by Gennadiy Sosnov on 24.10.2022.
//

#ifndef POLYTECH_WELCOMECONTAINER_H
#define POLYTECH_WELCOMECONTAINER_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpacerItem>
#include "../../widgets/buttons/StyledButton.h"

class StyledButton;

class WelcomeContainer : public QWidget{
    Q_OBJECT

    QVBoxLayout* mainLayout;
    QWidget* widget1;
    QHBoxLayout* layout1;
    QLabel* welcomeLabel1;

    QWidget* widget2;
    QHBoxLayout* layout2;
    QLabel* welcomeLabel2;

    QWidget* widget3;
    QHBoxLayout* layout3;
    StyledButton* openImageButton;

    QSpacerItem* hSpacer;
    QSpacerItem* vSpacer;

public:
    explicit WelcomeContainer(QWidget* parent = Q_NULLPTR);

signals:
    void openImageButtonClicked();

public slots:
    void setIsLight(bool isLight);
};


#endif //POLYTECH_WELCOMECONTAINER_H
