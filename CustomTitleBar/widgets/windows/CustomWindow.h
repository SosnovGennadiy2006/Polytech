//
// Created by genas on 04.10.2022.
//

#ifndef POLYTECH_CUSTOMWINDOW_H
#define POLYTECH_CUSTOMWINDOW_H

#include "../../widgets/windowClasses/FramelessWindow.h"

class CustomWindow : public FramelessWindow{
    Q_OBJECT

public:
    explicit CustomWindow(QWidget* parent = Q_NULLPTR);
};

#endif//POLYTECH_CUSTOMWINDOW_H
