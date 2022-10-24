//
// Created by Student on 20.10.2022.
//

#ifndef POLYTECH_CUSTOMBUTTON_H
#define POLYTECH_CUSTOMBUTTON_H

#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

class StyledButton : public QPushButton {
    Q_OBJECT

    QLabel* textLabel;
    QHBoxLayout* btnLayout;

public:
    explicit StyledButton(QWidget* parent = Q_NULLPTR);

    void setText(const QString& newText);
};


#endif//POLYTECH_CUSTOMBUTTON_H
