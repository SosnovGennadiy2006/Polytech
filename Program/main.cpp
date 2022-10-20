#include <QApplication>
#include "widgets/windows/MainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    auto* w = new MainWindow();
    w->show();

    return QApplication::exec();
}
