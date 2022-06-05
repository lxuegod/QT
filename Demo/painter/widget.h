#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMouseEvent>  //鼠标事件
#include <QPainter>  //画家事件
#include <QComboBox>
#include <QCloseEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void creatColorComboBox(QComboBox *comboBox);

protected:
    void mousePressEvent(QMouseEvent * ev);   //鼠标按下事件
    void paintEvent(QPaintEvent *);  //绘画事件
    void mouseMoveEvent(QMouseEvent *ev);  //鼠标移动事件
    void mouseReleaseEvent(QMouseEvent *ev);  //鼠标释放事件
    void closeEvent(QCloseEvent *event);  //窗口关闭事件
private:
    Ui::Widget *ui;\

    QPixmap pix;  //全局变量保存绘图
    QPoint lastPoint;  //保存鼠标上的最后一个值
    QPoint endPoint;  //保存鼠标最后一个值
    int fontSeize;

    QColor penColor;

private slots:
    void on_comboBoxBrush_currentIndexChanged(int index);

    void on_btn_savePix_clicked();
};

#endif // WIDGET_H
