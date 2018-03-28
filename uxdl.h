#ifndef UXDL_H
#define UXDL_H

#include <QtCharts/QChart>
#include <QtCore/QTimer>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QSplineSeries>




QT_CHARTS_USE_NAMESPACE

//![1]
class UXDL: public QChart
{
    Q_OBJECT
public:
    UXDL(QGraphicsItem *parent = 0, Qt::WindowFlags wFlags = 0);
    virtual ~UXDL();



public slots:
    void handleTimeout();

private:
    QTimer m_timer;
    QSplineSeries *m_series;
    QStringList m_titles;
    QValueAxis *m_axis;
    qreal m_step;
    qreal m_x;
    qreal m_y;
    QPoint hotpot;
    bool mousedown = false;
};

#endif // UXDL_H
