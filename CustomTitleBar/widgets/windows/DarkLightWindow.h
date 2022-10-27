//
// Created by Gennadiy Sosnov on 18.10.2022.
//

#ifndef POLYTECH_DARKLIGHTWINDOW_H
#define POLYTECH_DARKLIGHTWINDOW_H

#include "../../widgets/windowClasses/FramelessWindow.h"
#include "../../widgets/titleBars/DarkLightTitleBar.h"

class DarkLightWindow : public FramelessWindow{
    Q_OBJECT

protected:
    DarkLightTitleBar* titleBar;

public:
    explicit DarkLightWindow(QWidget* parent = Q_NULLPTR);
};


#endif//POLYTECH_DARKLIGHTWINDOW_H
