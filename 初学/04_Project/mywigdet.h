#ifndef MYWIGDET_H
#define MYWIGDET_H


#include <QWidget>//����ͷ�ļ�  QWidget ������

class mywigdet : public QWidget
{
    Q_OBJECT  //Q_OBJECT�꣬��������ʹ���źźͲ۵Ļ���

public:
    mywigdet(QWidget *parent = nullptr);  //���캯��
    ~mywigdet(); //��������
};
#endif // MYWIGDET_H
