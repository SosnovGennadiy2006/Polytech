//
// Created by Gennadiy Sosnov on 27.10.2022.
//

#include "WorkArea.h"

WorkArea::WorkArea(QWidget* parent) : QWidget{parent}
{
    setupUI();

    connect(enterImageButton, &StyledButton::clicked, this, &WorkArea::openImage);
}

void WorkArea::setupUI()
{
    setAttribute(Qt::WA_StyledBackground);
    setObjectName("workArea");
    setMaximumWidth(1500);
    setMinimumWidth(700);

    QFont bigFont;
    bigFont.setPixelSize(42);
    bigFont.setFamily("Calibri");
    QFont ordinaryFont;
    ordinaryFont.setPixelSize(32);
    ordinaryFont.setFamily("Calibri");
    QFont smallFont;
    smallFont.setPixelSize(28);
    smallFont.setFamily("Calibri");

    hSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    vSpacer = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    imageWidget = new QWidget(this);

    imageLayout = new QHBoxLayout(imageWidget);

    mainImage = new Image(imageWidget);

    imageLayout->addItem(hSpacer);
    imageLayout->addWidget(mainImage);
    imageLayout->addItem(hSpacer);

    optionsWidget = new QWidget(this);

    optionsLayout = new QHBoxLayout(optionsWidget);
    optionsLayout->setSpacing(5);

    enterImageButton = new StyledButton(optionsWidget);
    enterImageButton->setText("Enter image");
    enterImageButton->setObjectName("colorButton");
    enterImageButton->setFont(smallFont);

    addCircleButton = new StyledButton(optionsWidget);
    addCircleButton->setText("select circle");
    addCircleButton->setObjectName("colorButton");
    addCircleButton->setFont(smallFont);

    optionsLayout->addItem(hSpacer);
    optionsLayout->addWidget(enterImageButton);
    optionsLayout->addWidget(addCircleButton);

    infoWidget = new QWidget(this);
    infoWidget->hide();

    infoGrid = new QGridLayout(infoWidget);

    lbl1 = new QLabel(infoWidget);
    lbl1->setObjectName("tableInfoName");
    lbl1->setText("Minimum intensity:");
    lbl1->setFont(ordinaryFont);
    lbl1->setObjectName("colorText");

    lbl2 = new QLabel(infoWidget);
    lbl2->setObjectName("tableInfoName");
    lbl2->setText("Average intensity:");
    lbl2->setFont(ordinaryFont);
    lbl2->setObjectName("colorText");

    lbl3 = new QLabel(infoWidget);
    lbl3->setObjectName("tableInfoName");
    lbl3->setText("Maximum intensity:");
    lbl3->setFont(ordinaryFont);
    lbl3->setObjectName("colorText");

    info1 = new QLabel(infoWidget);
    info1->setObjectName("tableInfo");
    info1->setFont(ordinaryFont);
    info1->setText("");
    info1->setObjectName("dataText");

    info2 = new QLabel(infoWidget);
    info2->setObjectName("tableInfo");
    info2->setFont(ordinaryFont);
    info2->setText("");
    info2->setObjectName("dataText");

    info3 = new QLabel(infoWidget);
    info3->setObjectName("tableInfo");
    info3->setFont(ordinaryFont);
    info3->setText("");
    info3->setObjectName("dataText");

    infoGrid->addWidget(lbl1, 0, 0);
    infoGrid->addWidget(lbl2, 1, 0);
    infoGrid->addWidget(lbl3, 2, 0);
    infoGrid->addItem(hSpacer, 0, 1);
    infoGrid->addItem(hSpacer, 1, 1);
    infoGrid->addItem(hSpacer, 2, 1);
    infoGrid->addWidget(info1, 0, 2);
    infoGrid->addWidget(info2, 1, 2);
    infoGrid->addWidget(info3, 2, 2);

    mainLayout->addItem(vSpacer);
    mainLayout->addWidget(imageWidget);
    mainLayout->addWidget(optionsWidget);
    mainLayout->addWidget(infoWidget);
    mainLayout->addItem(vSpacer);
}

void WorkArea::openImage()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    if (QString::compare(fileName, QString()) != 0)
    {
        QImage image;
        bool valid = image.load(fileName);
        if (valid)
        {
            optionsWidget->show();
            mainImage->setPixmap(QPixmap::fromImage(image));
            return;
        }
    }
}