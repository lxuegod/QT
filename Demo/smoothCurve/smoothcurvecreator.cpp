#include "smoothcurvecreator.h"

//SmoothCurveCreator::SmoothCurveCreator(QWidget *parent) : QWidget(parent)
//{

//}

QPainterPath SmoothCurveCreator::createSmoothCurve(const QList<QPointF> &points)
{//创造光滑曲线  点
    QPainterPath path;
    int len = points.size();
    if(len < 2){
        return path;
    }

    //第一个点
    QList<QPointF> firstControlPoints;
    //第二个点
    QList<QPointF> secondControlPoints;
    calculateControlPoints(points,&firstControlPoints,&secondControlPoints);

    //path移动到第一个点
    path.moveTo(points[0].x(),points[0].y());

    //使用bezier曲线生成光滑的曲线
    for(int i = 0;i < len - 1; ++i){
        //三个参数 第一个点  第二个点 最后一个点
        path.cubicTo(firstControlPoints[i],secondControlPoints[i],points[i+1]);
    }
    return path;

}


void SmoothCurveCreator::calculateFirstControlPoints(double *&result,const double *rhs,int n)
{//创造第一个控制点
    result = new double[n];
    double * tmp = new double [n];
    double b = 2.0;
    result[0] = rhs[0] / b;

    //分解与正向替换
    for(int i = 1;i < n; i++){
        tmp[i] = 1 / b;
        b = (i < n-1 ? 4.0:3.5) - tmp[i];
        result[i] = (rhs[i] - result [i - 1])/b;
    }

    for(int i = 1; i < n; i++){
        result[n - i - 1] -= tmp[n - i] * result[n - i];  //反替代
    }
    delete tmp;
}

void SmoothCurveCreator::calculateControlPoints(const QList<QPointF> &knots,
                                                QList<QPointF> * firstControlPoints,
                                       QList<QPointF> * secondControlPoints)
{
    int n = knots.size() - 1;

    for(int i = 0; i < n; ++i){
        firstControlPoints->append(QPointF());
        secondControlPoints->append(QPointF());
    }

    if(n == 1){
        //特殊情况 Bezier curve 应该是直线
        //P1 = (2P0 + P3)/3
        (*firstControlPoints)[0].rx() = (2 * knots[0].x() + knots[1].x()) /3;
        (*secondControlPoints)[0].ry() = (2 * knots[0].y() + knots[1].y())/3;

        //P2 = 2P1 - P0
        (*secondControlPoints)[0].rx() = 2 * (*firstControlPoints)[0].x() - knots[0].x();
        (*secondControlPoints)[0].ry() = 2 * (*firstControlPoints)[0].y() - knots[0].y();
        return;
    }
    //计算第一个Bezier 控制点
    double * xs = 0;
    double * ys = 0;
    double *rhsx = new double[n];  //右侧向量
    double *rhsy = new double[n];  //右侧向量
    //设置右侧值
    for(int i = 1;i < n - 1; ++i){
        rhsx[i] = 4 * knots[i].x() + 2 * knots[i+1].x();
        rhsy[i] = 4* knots[i].y() + 2 * knots[i+1].y();
    }
    rhsx[0] = knots[0].x() + 2 * knots[1].x();
    rhsx[n-1] = (8 * knots[n-1].x() + knots[n].x())/2.0;
    rhsy[0] = knots[0].y() + 2 * knots[1].y();
    rhsy[n-1] = (8 * knots[n-1].y() + knots[n].y())/2.0;

    //计算第一控制点的坐标
    calculateFirstControlPoints(xs,rhsx,n);
    calculateFirstControlPoints(ys,rhsy,n);

    //填充控制输出点
    for(int i = 0; i < n; ++i){
        (*firstControlPoints)[i].rx() = xs[i];
        (*firstControlPoints)[i].ry() = ys[i];
        if(i < n - 1){
            (*secondControlPoints)[i].rx() = 2 * knots[i+1].x() - xs[i+1];
            (*secondControlPoints)[i].ry() = 2 * knots[i+1].y() - ys[i+1];
        }else {
            (*secondControlPoints)[i].rx() = (knots[n].x() + xs[n-1])/2;
            (*secondControlPoints)[i].ry() = (knots[n].y() + ys[n-1])/2;
        }
    }
    delete xs;
    delete ys;
    delete rhsx;
    delete rhsy;
}
