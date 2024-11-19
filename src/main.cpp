#include <QApplication>
#include <QMainWindow>

#include "hello.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    hello w;
    w.show();
    return a.exec();
}
