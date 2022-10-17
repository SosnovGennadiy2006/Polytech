//
// Created by Student on 17.10.2022.
//

#ifndef SRC_MAINWINDOW_H
#define SRC_MAINWINDOW_H

#include <QMainWindow>
#include "widgets/other/StyleSheetsHelper.h"

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = Q_NULLPTR);

    void setupUI();
};


#endif //SRC_MAINWINDOW_H
