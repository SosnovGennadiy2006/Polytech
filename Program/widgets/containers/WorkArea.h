//
// Created by Gennadiy Sosnov on 27.10.2022.
//

#ifndef POLYTECH_WORKAREA_H
#define POLYTECH_WORKAREA_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSpacerItem>
#include <QLabel>
#include <QFileDialog>
#include "../../widgets/buttons/StyledButton.h"
#include "../../widgets/other/Image.h"

class StyledButton;

class WorkArea : public QWidget
{
    Q_OBJECT

    QVBoxLayout *mainLayout;

    QWidget *imageWidget;
    QHBoxLayout *imageLayout;
    Image *mainImage;

    QWidget *optionsWidget;
    QHBoxLayout *optionsLayout;
    StyledButton *enterImageButton;
    StyledButton *addCircleButton;

    QWidget *infoWidget;
    QGridLayout *infoGrid;

    QLabel *lbl1;
    QLabel *lbl2;
    QLabel *lbl3;

    QLabel *info1;
    QLabel *info2;
    QLabel *info3;

    QSpacerItem *hSpacer;
    QSpacerItem *vSpacer;

public:
    explicit WorkArea(QWidget* parent = Q_NULLPTR);

    void setupUI();

public slots:
    void openImage();
};

#endif // POLYTECH_WORKAREA_H