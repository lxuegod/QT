#ifndef MYWIGDET_H
#define MYWIGDET_H


#include <QWidget>//包含头文件  QWidget 窗口类

class mywigdet : public QWidget
{
    Q_OBJECT  //Q_OBJECT宏，允许类中使用信号和槽的机制

public:
    mywigdet(QWidget *parent = nullptr);  //构造函数
    ~mywigdet(); //析构函数
};
#endif // MYWIGDET_H
