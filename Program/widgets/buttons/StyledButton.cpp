//
// Created by Gennadiy Sosnov on 20.10.2022.
//

#include "StyledButton.h"

StyledButton::StyledButton(QWidget* parent) : QPushButton{parent}
{
    setObjectName("styledButton");
    setCursor(QCursor(Qt::PointingHandCursor));

    btnLayout = new QHBoxLayout();
    btnLayout->setContentsMargins(0, 0, 0, 0);
    btnLayout->setSpacing(0);

    setLayout(btnLayout);

    textLabel = new QLabel(this);
    textLabel->setMouseTracking(false);
    textLabel->setAlignment(Qt::AlignCenter);

    layout()->addWidget(textLabel);
}

void StyledButton::setText(const QString& newText)
{
    textLabel->setText(newText);
}
