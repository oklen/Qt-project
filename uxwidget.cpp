#include "uxwidget.h"
#include "uxzoomchart.h"
#include "ui_widget.h"
#include <QPainter>
#include <QBrush>
#include <QDebug>
#include <cmath>


UXWidget::UXWidget(QWidget *parent) :
    QWidget(parent),
    pos{QPoint(0,0)},
    pos2{QPoint(0,0)},
    stage{1},
    chart{new UXZOOMCHART},
    vectorz{new QVector<qreal>}
{
    //To do: Need to give data to cdraw's helper.
    //Note: The set operation will automatically driver the full painting loop.
    //After draw draw done,You need to set the bool to enable slice analysis.

    connect(cdraw.helper,SIGNAL(pixmapupdate()),this,SLOT(update()));
}

int UXWidget::getINT(double a)
{
    int b = int(a);
    if ((a -b)>(0.1))
        return b+1;
    return b;
}

void UXWidget::paintEvent(QPaintEvent *event)
{
    if(!drawdone)
    {
        QPainter *painter = new QPainter(this);
        painter->drawPixmap(QRectF( rect()),cdraw.getpixmap(),QRectF( rect()));
        painter->end();
        return;
    }
//    qDebug() << "paint!";
    if (pos == QPoint(0,0)){
//        QPainter *painter = new QPainter(this);
//        painter->setRenderHint(QPainter::Antialiasing, true);
//        painter->setPen(QColor("black"));
//        QRadialGradient RadialGrad(QPointF(100,100),200,QPointF(200,200));
//        RadialGrad.setSpread(QGradient::ReflectSpread);
//        RadialGrad.setColorAt(0,Qt::white);
//        RadialGrad.setColorAt(1,Qt::lightGray);
//        painter->setBrush(QBrush(RadialGrad));
//        painter->drawRect(0,0,800,800);
//        painter->end();
    }
    else
    {

        if (stage == 3)
        {
//            QPainter *painter = new QPainter(this);
//            painter->setRenderHint(QPainter::Antialiasing, true);
//            painter->setPen(QColor("black"));
//            painter->drawLine(pos,pos2);
//            painter->setBrush(QBrush(Qt::cyan));
//            for (int j =0;j<100;j++)
//            for(int i = 0;i<100;i++)
//            {
//                painter->drawEllipse(QPoint(6*j,6*i),2,2);
//            }

            double k1 = double(pos.y() - pos2.y())/(pos.x()- pos2.x());
//switch axis
            qDebug() << "k1 " << k1;


//Begin Draw the Selected
            QPoint initPoint = QPoint(pos.x()/6,pos.y()/6);
            QPoint endPoint = QPoint(pos2.x()/6,pos2.y()/6);




            if (std::fabs(k1) > 1)
            {


                k1 = -1/(double((pos.y()- pos2.y()))/(pos.x() - pos2.x()));
                            qDebug() << "k1 " << k1;
                if (initPoint.y() < endPoint.y())
                    for (int i=0;i<std::abs(initPoint.y()-endPoint.y());i++)
                    {
                        //                qDebug() << k1*i;
//                        vectorx.append(getINT(k1*(i))*-6 + 6*getINT(initPoint.x()));
//                        vectory.append(6*getINT(initPoint.y()) + i*6);
                        vectorx.append(getINT(k1*(i)*-6) + getINT(6*initPoint.x()));
                        vectory.append(getINT(6*initPoint.y()) + i*6);
                    }
                else
                    for (int i=0;i<std::abs(initPoint.y()-endPoint.y());i++)
                    {
                        //                    qDebug() << k1*i;
                        vectorx.append(getINT(k1*(i))*6 + 6*getINT(initPoint.x()));
                        vectory.append(6*getINT(initPoint.y()) - i*6);
                    }
            }
            else
            {
                if (initPoint.x() < endPoint.x())
                    for (int i=0;i<std::abs(initPoint.x()-endPoint.x());i++)
                    {
                        //                qDebug() << k1*i;
                        vectory.append(getINT(k1*(i))*6 + 6*getINT(initPoint.y()));
                        vectorx.append(6*getINT(initPoint.x()) + i*6);
                    }
                else
                    for (int i=0;i<std::abs(initPoint.x()-endPoint.x());i++)
                    {
                        //                    qDebug() << k1*i;
                        vectory.append(-getINT(k1*(i))*6 + 6*getINT(initPoint.y()));
                        vectorx.append(6*getINT(initPoint.x()) - i*6);
                    }
            }
//            painter->setBrush(Qt::red);
//            for (int j =0;j<vectorx.size();j++)
//            {
//                painter->drawEllipse(QPoint(vectorx.at(j),vectory.at(j))
//                        ,2,2);
//            }
//            painter->end();
            stage = 1;
            //Data Get Here
            QSplineSeries *series = new QSplineSeries();
            for(int i = 0;i<vectorx.count();i++){
                series->append(i,std::sin(vectorx.at(i) + vectory.at(i)));
                vectorz->append(std::sin(vectorx.at(i) + vectory.at(i)));
            }
            series->setName("Sample data");
            chart->setTitle("SLiCE SHOW");
            chart->setTitleBrush(QBrush(Qt::white));
            chart->addSeries(series);
            chart->createDefaultAxes();
            chart->legend()->setVisible(true);
            chart->legend()->setAlignment(Qt::AlignBottom);


            chart->setPlotAreaBackgroundBrush(QBrush(QColor("#4a484d")));
            chart->setPlotAreaBackgroundVisible(true);

            chart->setBackgroundBrush(QBrush(QColor("#4c4c4c")));

            QFont labelsFont;
            labelsFont.setPixelSize(12);
            chart->axisX(series)->setLabelsFont(labelsFont);
            chart->axisY(series)->setLabelsFont(labelsFont);

//            // Customize axis colors
            QPen axisPen(QColor(255,255,255,70));
            axisPen.setWidth(2);
            chart->axisX(series)->setLinePen(axisPen);
            chart->axisY(series)->setLinePen(axisPen);
            chart->axisY(series)->setLabelsColor(QColor("white"));
            chart->axisX(series)->setLabelsColor(QColor("white"));
//            chart->legend()->setColor("white");
            chart->legend()->setBrush(QBrush(Qt::white));
//            chart->legend()->setBackgroundVisible(true);
            chart->legend()->setLabelColor(Qt::white);
//            // Customize axis label colors
//            QBrush axisBrush(Qt::white);
//            chart->axisX(series)->setLabelsBrush(axisBrush);
//            chart->axisY(series)->setLabelsBrush(axisBrush);

            // Customize grid lines and shades
            chart->axisX(series)->setGridLineVisible(true);
            chart->axisY(series)->setGridLineVisible(true);
            chart->axisX(series)->setGridLineColor(QColor(255,255,255,70));
            chart->axisY(series)->setGridLineColor(QColor(255,255,255,70));
//            QChartView *chartview = new QChartView(chart);
//            chartview->setParent(this);
//            chartview->setGeometry(0,580,600,330);
//            chartview->show();
            vectorx.clear();
            vectory.clear();
            qDebug() << "Stage 3";
        }
    }
}

UXWidget::~UXWidget()
{
//    delete ui;
}

void UXWidget::mousePressEvent(QMouseEvent *event)
{
    if(stage == 2)
    {
        pos2 = event->pos();
        qDebug() << "pos2:" << pos2;
        chart->removeAllSeries();

    }
    if(stage ==1)
    {
        pos = event->pos();
        qDebug() << "pos:" << pos;
        vectorz->clear();
    }
     stage +=1;
    update();
}

UXZOOMCHART* UXWidget::getchart()
{
    return chart;
}

void UXWidget::manualactive(QPoint xy)
{
    qDebug() << "manual activte";
    if(stage == 2)
    {
        pos2 = xy*10;
        chart->removeAllSeries();

    }
    if(stage ==1)
    {
        pos = xy*10;
        vectorz->clear();
    }
    qDebug() << "Be Actived:" <<xy << "stage:" << stage;
    stage+=1;
    if (pos == QPoint(0,0)){
    }
    else
    {

        if (stage == 3)
        {

            for (int j =0;j<100;j++)
            for(int i = 0;i<100;i++)
            {
            }

            double k1 = double(pos.y() - pos2.y())/(pos.x()- pos2.x());
//switch axis
            qDebug() << "k1 " << k1;


//Begin Draw the Selected
            QPoint initPoint = QPoint(pos.x()/6,pos.y()/6);
            QPoint endPoint = QPoint(pos2.x()/6,pos2.y()/6);




            if (std::fabs(k1) > 1)
            {


                k1 = -1/(double((pos.y()- pos2.y()))/(pos.x() - pos2.x()));
                            qDebug() << "k1 " << k1;
                if (initPoint.y() < endPoint.y())
                    for (int i=0;i<std::abs(initPoint.y()-endPoint.y());i++)
                    {
                        //                qDebug() << k1*i;
//                        vectorx.append(getINT(k1*(i))*-6 + 6*getINT(initPoint.x()));
//                        vectory.append(6*getINT(initPoint.y()) + i*6);
                        vectorx.append(getINT(k1*(i)*-6) + getINT(6*initPoint.x()));
                        vectory.append(getINT(6*initPoint.y()) + i*6);
                    }
                else
                    for (int i=0;i<std::abs(initPoint.y()-endPoint.y());i++)
                    {
                        //                    qDebug() << k1*i;
                        vectorx.append(getINT(k1*(i))*6 + 6*getINT(initPoint.x()));
                        vectory.append(6*getINT(initPoint.y()) - i*6);
                    }
            }
            else
            {
                if (initPoint.x() < endPoint.x())
                    for (int i=0;i<std::abs(initPoint.x()-endPoint.x());i++)
                    {
                        //                qDebug() << k1*i;
                        vectory.append(getINT(k1*(i))*6 + 6*getINT(initPoint.y()));
                        vectorx.append(6*getINT(initPoint.x()) + i*6);
                    }
                else
                    for (int i=0;i<std::abs(initPoint.x()-endPoint.x());i++)
                    {
                        //                    qDebug() << k1*i;
                        vectory.append(-getINT(k1*(i))*6 + 6*getINT(initPoint.y()));
                        vectorx.append(6*getINT(initPoint.x()) - i*6);
                    }
            }
            for (int j =0;j<vectorx.size();j++)
            {

            }
            stage = 1;

            QSplineSeries *series = new QSplineSeries();
            for(int i = 0;i<vectorx.count();i++){
                series->append(i,std::sin(vectorx.at(i) + vectory.at(i)));
                vectorz->append(std::sin(vectorx.at(i) + vectory.at(i)));
            }
            series->setName("Sample data");
            chart->setTitle("SLiCE SHOW");
            chart->addSeries(series);
            chart->createDefaultAxes();
            chart->legend()->setVisible(true);
            chart->legend()->setAlignment(Qt::AlignBottom);

            chart->setPlotAreaBackgroundBrush(QBrush(QColor("#4a484d")));
            chart->setPlotAreaBackgroundVisible(true);

            chart->setBackgroundBrush(QBrush(QColor("#4c4c4c")));

            QFont labelsFont;
            labelsFont.setPixelSize(12);
            chart->axisX(series)->setLabelsFont(labelsFont);
            chart->axisY(series)->setLabelsFont(labelsFont);

//            // Customize axis colors
            QPen axisPen(QColor(255,255,255,70));
            axisPen.setWidth(2);
            chart->setTitleBrush(QBrush(Qt::white));
            chart->axisX(series)->setLinePen(axisPen);
            chart->axisY(series)->setLinePen(axisPen);
            chart->axisY(series)->setLabelsColor(QColor("white"));
            chart->axisX(series)->setLabelsColor(QColor("white"));
//            chart->legend()->setColor("white");
            chart->legend()->setBrush(QBrush(Qt::white));
//            chart->legend()->setBackgroundVisible(true);
            chart->legend()->setLabelColor(Qt::white);
//            // Customize axis label colors
//            QBrush axisBrush(Qt::white);
//            chart->axisX(series)->setLabelsBrush(axisBrush);
//            chart->axisY(series)->setLabelsBrush(axisBrush);

            // Customize grid lines and shades
            chart->axisX(series)->setGridLineVisible(true);
            chart->axisY(series)->setGridLineVisible(true);
            chart->axisX(series)->setGridLineColor(QColor(255,255,255,70));
            chart->axisY(series)->setGridLineColor(QColor(255,255,255,70));

//            QChartView *chartview = new QChartView(chart);
//            chartview->setParent(this);
//            chartview->setGeometry(0,580,600,330);
//            chartview->show();
            vectorx.clear();
            vectory.clear();
            qDebug() << "Stage 3";
        }
    }
    update();
}

//void UXWidget::removez()
//{
//    vectorz->clear();
//}
