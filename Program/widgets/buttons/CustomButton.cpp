//
// Created by Student on 20.10.2022.
//

#include "CustomButton.h"

CustomButton::CustomButton(QWidget* parent) : QPushButton{parent}
{
    setObjectName("customButton");
    setCursor(QCursor(Qt::PointingHandCursor));
}
