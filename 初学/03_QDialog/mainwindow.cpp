﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击一个按钮 弹出一个对话框
    connect(ui->actionnew,&QAction::triggered,[=] () {
        //对话框  分类
        //模态对话框(不可以对其他的窗口进行操作)  非模态对话框(可以对其他的窗口进行操作)
        //模态的创建  阻塞功能
//        QDialog dlg(this);
//        dlg.resize(1000,1000);
//        dlg.exec();

//           qDebug() <<"模态对话框弹出了";

        //非模态的对话框的创建
        QDialog * dlg2 = new QDialog(this);
        dlg2->resize(1000,1000);
        dlg2->show();
        dlg2->setAttribute(Qt::WA_DeleteOnClose);   //55号 属性

         qDebug() <<"非模态对话框弹出了";


         //消息的对话框
         //错误对话框
         //QMessageBox::critical(this,"critical","错误");

         //消息对话框
         //QMessageBox::information(this,"info","信息");

         //提问对话框
         //参数1 父亲   参数2 标题  参数3 提示内容  参数4 按键类型  参数5 默认关联回车键
//         if(QMessageBox::Save == QMessageBox::question(this,"ques","提问",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Cancel))
//         {
//             qDebug()<<"选择的是保存";
//         }
//         else
//         {
//              qDebug()<<"选择的是取消";
//         }

         //警告对话框
         //QMessageBox::warning(this,"waring","警告");

         //其他的标准对话框
         //颜色对话框
//         QColor color = QColorDialog::getColor(QColor(255,0,0));
//         qDebug()<<"r= "<<color.red()<<"g= "<<color.green()<<"b = "<< color.blue();

         //文件对话框   参数1 父亲  参数2 标题  参数3 默认打开路径  参数4 过滤文件格式
         //返回值是路径
//         QString str = QFileDialog::getOpenFileName(this,"打开文件","F:\\桌面","(*.txt)");
//         qDebug()<<str;

         //字体对话框
//         bool flag;
//        QFont font = QFontDialog::getFont(&flag,QFont("华文彩云",36));
//         qDebug()<<"字体:"<<font.family().toUtf8().data()<<"字号"<<font.pointSize()<<"是否倾斜"<<font.italic();




    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

