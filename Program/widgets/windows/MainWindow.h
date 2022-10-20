//
// Created by genas on 03.10.2022.
//

#ifndef NOTESOFFICE_MAINWINDOW_H
#define NOTESOFFICE_MAINWINDOW_H

#include "widgets/windows/DarkLightWindow.h"
#include "../../widgets/other/StyleSheetsHelper.h"

class MainWindow : public DarkLightWindow{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = Q_NULLPTR);
};


#endif//NOTESOFFICE_MAINWINDOW_H
