#include "dialoglist.h"
#include "ui_dialoglist.h"
#include <QToolButton>
#include "widget.h"
#include <QMessageBox>
#include <QDebug>

DialogList::DialogList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogList)
{
    ui->setupUi(this);
    //设置标题
    setWindowTitle("MyQQ");
    //设置图标
    setWindowIcon(QPixmap(":/Imag/10.jpg"));



    //人物名称
    QStringList nameList;
    nameList<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9"<<"10";
    //人物头像
    QList<QString> iconList;
    iconList<<"10.jpg"<<"11.jpg"<<"12.jpg"<<"13.png"<<"14.png"<<
              "3.png"<<"5.jpg"<<"6.png"<<"7.png"<<"8.png";
    //将10个人物用QVector进行维护
    QVector<QToolButton*> vToolbtn;
    for(int i=0;i<10;i++)
    {
        //设置列表成员
        QToolButton* btn = new QToolButton;
        //设置文字
        btn->setText(nameList[i]);
        //设置头像
        QString str = QString(":/Imag/%1").arg(iconList.at(i));
        btn->setIcon(QIcon(str));
        //设置头像大小
        btn->setIconSize(QSize(100,100));
        //设置按钮风格 透明
        btn->setAutoRaise(true);
        //设置文字和图片一起显示
        btn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        //加到垂直布局中
        ui->verticalLayout->addWidget(btn);
        vToolbtn.push_back(btn);
        isShow.push_back(false);

   }

    //对9个按钮 添加信号槽
        for(int i=0;i<vToolbtn.size();i++)
        {
            connect(vToolbtn[i],&QToolButton::clicked,[=](){

                QString str2 = QString("您打开了%1的窗口").arg(vToolbtn[i]->text());
                qDebug()<<str2;


                //如果被打开了，就不要再次打开
                if(isShow[i])
                {
                    QString str = QString("%1窗口已经被打开了").arg(vToolbtn[i]->text());
                    QMessageBox::warning(this,"警告",str);
                    return;
                }
                isShow[i] = true;
                //弹出聊天对话框
                //构造聊天窗口，对窗口名称和头像进行初始化
                //参数1 顶层方式弹出(关闭dialoglist控件窗口，widget窗口不会关闭)  参数2 窗口名字
                Widget* widget = new Widget(0,vToolbtn[i]->text());
                //设置窗口标题
                widget->setWindowTitle(vToolbtn[i]->text());
                //设置窗口头像
                widget->setWindowIcon(vToolbtn[i]->icon());
                //进行显示
                widget->show();
                //关闭窗口时调整状态为false
                connect(widget,&Widget::closeWidget,[=](){
                    isShow[i] = false;
                });
            });
        }


}

DialogList::~DialogList()
{
    delete ui;
}
