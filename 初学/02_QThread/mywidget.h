#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "mythread.h"
#include <QThread>

namespace Ui {
class myWidget;
}

class myWidget : public QWidget
{
    Q_OBJECT

public:
    explicit myWidget(QWidget *parent = 0);
    ~myWidget();

    void dealSingnal();
    void dealClose();

signals:
    void startThread();

private slots:
    void on_btnStart_clicked();

    void on_btnStop_clicked();

private:
    Ui::myWidget *ui;
    myThread * myT;
    QThread * thread;
};

#endif // MYWIDGET_H
