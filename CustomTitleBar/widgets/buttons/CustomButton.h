//
// Created by genas on 03.10.2022.
//

#ifndef POLYTECH_CUSTOMBUTTON_H
#define POLYTECH_CUSTOMBUTTON_H

#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>

class CustomButton : public QPushButton{
    Q_OBJECT

    QLabel* textLabel;
    QHBoxLayout* btnLayout;

public:
    explicit CustomButton(QWidget* parent = Q_NULLPTR) : QPushButton{parent}
    {
        btnLayout = new QHBoxLayout();
        btnLayout->setContentsMargins(0, 0, 0, 0);
        btnLayout->setSpacing(0);

        setLayout(btnLayout);

        textLabel = new QLabel(this);
        textLabel->setMouseTracking(false);
        textLabel->setAlignment(Qt::AlignCenter);

        layout()->addWidget(textLabel);
    }

    void setText(const QString& newText)
    {
        textLabel->setText(newText);
    }

    void setIcon(const QPixmap& iconPixmap)
    {
        textLabel->setPixmap(iconPixmap);
    }
};

#endif//POLYTECH_CUSTOMBUTTON_H
