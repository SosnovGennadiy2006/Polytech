//
// Created by Gennadiy Sosnov on 03.10.2022.
//

#ifndef POLYTECH_SIMPLETITLEBAR_H
#define POLYTECH_SIMPLETITLEBAR_H

#include "../../widgets/titleBars/TitleBar.h"

class SimpleTitleBar : public TitleBar{
    Q_OBJECT

public:
    explicit SimpleTitleBar(QWidget* parent = Q_NULLPTR);
    ~SimpleTitleBar() override;

protected:
    QLabel* logoLabel;
    QLabel* titleLabel;
};


#endif//POLYTECH_SIMPLETITLEBAR_H
