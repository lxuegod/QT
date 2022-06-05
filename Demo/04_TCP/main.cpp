#include "serverwidget.h"
#include <QApplication>
#include "clianwidget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ServerWidget w;
    w.show();

    ClianWidget w2;
    w2.show();

    return a.exec();
}
