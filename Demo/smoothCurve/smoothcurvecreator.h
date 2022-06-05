#ifndef SMOOTHCURVECREATOR_H
#define SMOOTHCURVECREATOR_H

#include <QPointF>
#include <QList>
#include <QPainterPath>

class SmoothCurveCreator //: public QWidget
{
    //Q_OBJECT
public:
    //explicit SmoothCurveCreator(QWidget *parent = nullptr);

    static QPainterPath createSmoothCurve(const QList<QPointF> &points);

private:
    static void calculateFirstControlPoints(double * & result,const double * rhs,int n);

    static void calculateControlPoints(const QList<QPointF> & knots,
                                       QList<QPointF> * firstControlPoints,
                                       QList<QPointF> * secondControlPoints);

//signals:

//public slots:
};

#endif // SMOOTHCURVECREATOR_H
