//
// Created by Student on 20.10.2022.
//

#ifndef POLYTECH_CUSTOMBUTTON_H
#define POLYTECH_CUSTOMBUTTON_H

#include <QPushButton>

class StyledButton : public QPushButton {
    Q_OBJECT

public:
    explicit StyledButton(QWidget* parent = Q_NULLPTR);
};


#endif//POLYTECH_CUSTOMBUTTON_H
