#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>
#include <QPen>
#include <QMenuBar>
#include <QFile>
#include <QFileDialog>
#include <QBuffer>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //设置窗口
    this->resize(1200,1200);
    this->setWindowTitle("画板");
    //设置字体大小编辑框
    //ui->lineEditFont->resize(this->width()/3,this->height()/40);
    ui->lineEditFont->resize(100, 50);
    //移到左下角
    ui->lineEditFont->move(0,this->height() - ui->lineEditFont->height());

    //把窗口的全局设置为画纸
    pix = QPixmap(this->width(),this->height());
    pix.fill(Qt::white);   //画板的背景颜色

    ui->comboBoxBrush->resize(115,65);
    ui->comboBoxBrush->move(0, 0);
    creatColorComboBox(ui->comboBoxBrush);

    //save按钮  保存所画图像
    ui->btn_savePix->resize(100, 100);
    ui->btn_savePix->move(this->width() - ui->btn_savePix->width(), 0);

}

Widget::~Widget()
{
    delete ui;
}


//鼠标按下事件的重写

//鼠标按下事件
void Widget::mousePressEvent(QMouseEvent * ev)
{
    if(ev->button() == Qt::LeftButton){
        //确定鼠标的位置
        lastPoint = ev->pos();
        endPoint = lastPoint;
        //qDebug()<<"鼠标按下";
  }
    //按下左键清空之前画的东西
    if(ev->button() == Qt::RightButton){
        QPixmap clearPix = QPixmap();
        pix = clearPix;
        pix = QPixmap(this->width(),this->height());
        pix.fill(Qt::white);
        //重置字体大小编辑框的大小  保持与界面协调
        //ui->lineEditFont->resize(this->width()/3,this->height()/10);
        ui->lineEditFont->resize(100, 50);
        ui->lineEditFont->move(0,this->height() - ui->lineEditFont->height());
        ui->btn_savePix->move(this->width() - ui->btn_savePix->width(), 0);
        update();
    }
}

//鼠标移动事件
void Widget::mouseMoveEvent(QMouseEvent * ev)
{
    if(ev->buttons() & Qt::LeftButton){
        endPoint = ev->pos();
        //qDebug()<<"鼠标移动";
        update();
    }
}

//鼠标释放事件
void Widget::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton){
        //qDebug()<<"鼠标左键释放了";
        endPoint = ev->pos();
        update();
    }

}


//绘图事件
void Widget::paintEvent(QPaintEvent *)
{
    QPainter pp(&pix);  //保存的绘图
    QPainter painter(this);
    //设置画笔
    QPen pen;
    //pen.setColor(Qt::red);
    pen.setColor(penColor);
    fontSeize = ui->lineEditFont->text().toInt();
    pen.setWidth(fontSeize);
    pp.setPen(pen);
    pp.drawLine(lastPoint,endPoint);
    lastPoint = endPoint;
    painter.drawPixmap(0,0,pix);
}


void Widget::creatColorComboBox(QComboBox *comboBox)
{
    QPixmap pix(16,16);
    QPainter painter(&pix);
    painter.fillRect(0,0,16,16,Qt::red);
    comboBox->addItem(QIcon(pix),tr("红色"),QColor(Qt::red));
    painter.fillRect(0,0,16,16,Qt::white);
    comboBox->addItem(QIcon(pix),tr("白色"),QColor(Qt::white));
    painter.fillRect(0,0,16,16,Qt::black);
    comboBox->addItem(QIcon(pix),tr("黑色"),QColor(Qt::black));
    painter.fillRect(0,0,16,16,Qt::green);
    comboBox->addItem(QIcon(pix),tr("绿色"),QColor(Qt::green));
    painter.fillRect(0,0,16,16,Qt::blue);
    comboBox->addItem(QIcon(pix),tr("蓝色"),QColor(Qt::blue));
    painter.fillRect(0,0,16,16,Qt::yellow);
    comboBox->addItem(QIcon(pix),tr("黄色"),QColor(Qt::yellow));
    comboBox->addItem(tr("不选"),QColor(Qt::transparent));
}

void Widget::on_comboBoxBrush_currentIndexChanged(int index)
{
     QColor color = ui->comboBoxBrush->itemData(index,Qt::UserRole).value<QColor>();
     // qDebug()<<color;
    penColor=color;
     //setPenColor(color);

}


void Widget::on_btn_savePix_clicked()
{
    QString filePath;
    filePath = QFileDialog::getSaveFileName(this,"open","../",tr("Images(*.png);;Images(*.jpg)"));
    pix.save(filePath);
}

void Widget::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton btn;
    btn = QMessageBox::question(this,tr("是否保存"),QString(tr("确认保存")),QMessageBox::Yes|QMessageBox::No);
    if(btn == QMessageBox::Yes){
        on_btn_savePix_clicked();
    }if(btn == QMessageBox::No) {
        event->accept();
    }
}
