//
// Created by genas on 18.10.2022.
//

#ifndef POLYTECH_DARKLIGHTTITLEBAR_H
#define POLYTECH_DARKLIGHTTITLEBAR_H

#include "../../widgets/titleBars/SimpleTitleBar.h"

class DarkLightTitleBar : public SimpleTitleBar{
    Q_OBJECT

    bool isLight;

public:
    explicit DarkLightTitleBar(QWidget* parent = Q_NULLPTR);
    ~DarkLightTitleBar();

protected:
    CustomButton* changeModeButton;

signals:
    void ModeChanged(bool isLight);

public slots:
    virtual void toggleMode();
};


#endif//POLYTECH_DARKLIGHTTITLEBAR_H
