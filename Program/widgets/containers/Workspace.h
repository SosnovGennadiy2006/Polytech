//
// Created by Gennadiy Sosnov on 20.10.2022.
//

#ifndef POLYTECH_WORKSPACE_H
#define POLYTECH_WORKSPACE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSpacerItem>
#include <QLabel>
#include <QFileDialog>
#include "../../widgets/buttons/StyledButton.h"
#include "../../widgets/other/Image.h"
#include "WelcomeContainer.h"
#include "WorkArea.h"

class StyledButton;

class Workspace : public QWidget{
    Q_OBJECT

    QVBoxLayout* mainLayout;

    QWidget* welcomeWrapper;

    QHBoxLayout* welcomeLayout;

    WelcomeContainer* welcome;

    QWidget *workAreaWrapper;

    QHBoxLayout *workAreaLayout;

    WorkArea* workArea;

    QSpacerItem* hSpacer;

public:
    explicit Workspace(QWidget* parent = Q_NULLPTR);

    void setupUI();

public slots:
    void setIsLight(bool isLight);
    void openImage();
};

#endif//POLYTECH_WORKSPACE_H
