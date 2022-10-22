//
// Created by genas on 03.10.2022.
//

#ifndef NOTESOFFICE_MAINWINDOW_H
#define NOTESOFFICE_MAINWINDOW_H

#include "widgets/windows/DarkLightWindow.h"
#include "../../widgets/other/StyleSheetsHelper.h"
#include "../../widgets/containers/Workspace.h"

class MainWindow : public DarkLightWindow{
    Q_OBJECT

    Workspace* workspace;

public:
    explicit MainWindow(QWidget* parent = Q_NULLPTR);

    void setupUI();
    void setupConnections();

public slots:
    void changeMode(bool isLight);
};


#endif//NOTESOFFICE_MAINWINDOW_H
