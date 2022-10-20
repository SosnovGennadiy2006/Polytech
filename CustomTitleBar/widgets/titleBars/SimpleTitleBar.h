//
// Created by genas on 03.10.2022.
//

#ifndef NOTESOFFICE_SIMPLETITLEBAR_H
#define NOTESOFFICE_SIMPLETITLEBAR_H

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


#endif//NOTESOFFICE_SIMPLETITLEBAR_H
