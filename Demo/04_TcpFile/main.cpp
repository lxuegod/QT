#include "severwidget.h"
#include <QApplication>
#include "clianwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SeverWidget w;
    w.show();

    clianwidget w2;
    w2.show();

    return a.exec();
}
