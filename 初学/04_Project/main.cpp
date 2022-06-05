#include "mywigdet.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mywigdet w;
    w.show();
    return a.exec();
}
