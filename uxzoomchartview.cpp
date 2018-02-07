#include "uxzoomchartview.h"
#include <QtGui/QMouseEvent>
#include <QCategoryAxis>
#include <QDebug>
#include <cmath>

UXZOOMCHARTVIEW::UXZOOMCHARTVIEW(UXZOOMCHART *mchart, QWidget *parent) :
    QChartView(mchart, parent),
    m_isTouching(false),
//    debugtext(new QGraphicsSimpleTextItem(mchart)),
    debugtext2(new QGraphicsSimpleTextItem(mchart))
  ,pix(new QPixmap(5,5)),
    gpix(new QGraphicsPixmapItem)
{
    setRubberBand(QChartView::RectangleRubberBand);
    setMouseTracking(true);
    setBackgroundBrush(QBrush(QColor(74,74,74)));
    chart()->setAnimationOptions(QChart::SeriesAnimations);

}

bool UXZOOMCHARTVIEW::viewportEvent(QEvent *event)
{

    return QChartView::viewportEvent(event);
}

void UXZOOMCHARTVIEW::mousePressEvent(QMouseEvent *event)
{
    if (m_isTouching)
        return;
    QChartView::mousePressEvent(event);
}

void UXZOOMCHARTVIEW::mouseMoveEvent(QMouseEvent *event)
{
qDebug()<< "Move! " << yvalue->length();
    if (m_isTouching)
        return;
    if (datacursor &&(yvalue->length() !=0) ) {
        qreal xval = this->chart()->mapToValue(event->pos()).x();
        qreal yval = this->chart()->mapToValue(event->pos()).y();


//        debugtext->setBrush(QBrush(Qt::white));
//        debugtext->setFont(QFont("Times", 15, QFont::Bold));

        debugtext2->setBrush(QBrush(Qt::white));
        debugtext2->setFont(QFont("Times", 15, QFont::Bold));


        if(xval>0 && ((xval+1) < yvalue->length()))
        {
            if(int(xval+1) <= yvalue->length() )
            debugtext2->setText(QString::number(yvalue->at(int(xval))
                                                +(xval - int(xval))*(
                                                    yvalue->at(int(xval)+1) - yvalue->at(int(xval))
                                                    )));
            else
                debugtext2->setText(QString::number(yvalue->at(int(xval))));

//            debugtext->setText( QString::number(xval) + " "
//                                + QString::number(yvalue->length()) + " "+
//                                QString::number(yvalue->at(int(xval)))+ " "
//                                + QString::number(chart()->mapToPosition(
//                                                      QPointF(
//                                                      xval,yvalue->at(int(xval))
//                                                          )
//                                                      ).y()));

//            debugtext->setPos(chart()->mapToPosition(QPointF( xval,
//                                                              chart()->mapToValue(event->pos()).y()
//                                                     )));


            if(int(xval+1) <= yvalue->length() ){
                if(!(chart()->mapToPosition(
                            QPointF(xval,yvalue->at(int(xval))+(xval - int(xval))*(
                                        yvalue->at(int(xval)+1) - yvalue->at(int(xval))
                                        ))).y()-2.5 > 56)  ||
                        !(chart()->mapToPosition(
                             QPointF(xval,yvalue->at(int(xval))+(xval - int(xval))*(
                                         yvalue->at(int(xval)+1) - yvalue->at(int(xval))
                                         ))).y()-2.5 < 570) )
                    return;
                debugtext2->setPos(
                            QPointF(
                                event->x(),chart()->mapToPosition(
                                    QPointF(xval,yvalue->at(int(xval))+(xval - int(xval))*(
                                                yvalue->at(int(xval)+1) - yvalue->at(int(xval))
                                                ))).y()));
                pix->fill(Qt::red);


                gpix->setPixmap(*pix);
                gpix->setParentItem(chart());
                gpix->setPos(
                            QPointF(
                                event->x()-2.5,chart()->mapToPosition(
                                    QPointF(xval,yvalue->at(int(xval))+(xval - int(xval))*(
                                                yvalue->at(int(xval)+1) - yvalue->at(int(xval))
                                                ))).y()-2.5
                                ));
            }
        }
     }
    QChartView::mouseMoveEvent(event);
}

void UXZOOMCHARTVIEW::mouseReleaseEvent(QMouseEvent *event)
{
    if (m_isTouching)
        m_isTouching = false;

    // Because we disabled animations when touch event was detected
    // we must put them back on.
    chart()->setAnimationOptions(QChart::SeriesAnimations);

    QChartView::mouseReleaseEvent(event);
}

//![1]
void UXZOOMCHARTVIEW::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Plus:
        chart()->zoomIn();
        break;
    case Qt::Key_Minus:
        chart()->zoomOut();
        break;
//![1]
    case Qt::Key_Left:
        chart()->scroll(-10, 0);
        break;
    case Qt::Key_Right:
        chart()->scroll(10, 0);
        break;
    case Qt::Key_Up:
        chart()->scroll(0, 10);
        break;
    case Qt::Key_Down:
        chart()->scroll(0, -10);
        break;
    default:
        QGraphicsView::keyPressEvent(event);
        break;
    }
}

void UXZOOMCHARTVIEW::enablevis()
{
    datacursor = true;
}
