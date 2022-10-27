//
// Created by Gennadiy Sosnov on 03.10.2022.
//

#ifndef POLYTECH_MAINWINDOW_H
#define POLYTECH_MAINWINDOW_H

#include <QVBoxLayout>
#include "widgets/windows/DarkLightWindow.h"
#include "../../widgets/other/StyleSheetsHelper.h"
#include "../../widgets/containers/Workspace.h"

class MainWindow : public DarkLightWindow{
    Q_OBJECT

    QVBoxLayout* mainLayout;

    Workspace* workspace;

public:
    explicit MainWindow(QWidget* parent = Q_NULLPTR);

    void setupUI();
    void setupConnections();

public slots:
    void changeMode(bool isLight);
};


#endif//POLYTECH_MAINWINDOW_H
