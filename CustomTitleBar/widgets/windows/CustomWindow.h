//
// Created by genas on 04.10.2022.
//

#ifndef NOTESOFFICE_CUSTOMWINDOW_H
#define NOTESOFFICE_CUSTOMWINDOW_H

#include "../../widgets/windowClasses/FramelessWindow.h"

class CustomWindow : public FramelessWindow{
    Q_OBJECT

public:
    explicit CustomWindow(QWidget* parent = Q_NULLPTR);
};

#endif//NOTESOFFICE_CUSTOMWINDOW_H
