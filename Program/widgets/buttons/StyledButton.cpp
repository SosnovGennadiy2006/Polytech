//
// Created by Student on 20.10.2022.
//

#include "StyledButton.h"

StyledButton::StyledButton(QWidget* parent) : QPushButton{parent}
{
    setObjectName("styledButton");
    setCursor(QCursor(Qt::PointingHandCursor));
}
