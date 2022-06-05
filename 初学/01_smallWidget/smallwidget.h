#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QWidget>

namespace Ui {
class smallWidget;
}

class smallWidget : public QWidget
{
    Q_OBJECT

public:
    explicit smallWidget(QWidget *parent = nullptr);
    ~smallWidget();

    //设置数字
    void setNum(int num);

    //获取数字
    int getNum();

private:
    Ui::smallWidget *ui;
};

#endif // SMALLWIDGET_H
