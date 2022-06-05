#ifndef CLIANWIDGET_H
#define CLIANWIDGET_H

#include <QWidget>
#include <QTcpSocket>  //通信套接字

namespace Ui {
class ClianWidget;
}

class ClianWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClianWidget(QWidget *parent = 0);
    ~ClianWidget();

private slots:
    void on_pushButtonConnect_clicked();

    void on_btn_send_clicked();

    void on_btn_close_clicked();

private:
    Ui::ClianWidget *ui;

    QTcpSocket * tcpSocket;//通信套接字
};

#endif // CLIANWIDGET_H
