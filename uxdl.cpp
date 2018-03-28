#include "uxdl.h"

#include <QtCharts/QAbstractAxis>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCore/QRandomGenerator>
#include <QtCore/QDebug>

UXDL::UXDL(QGraphicsItem *parent, Qt::WindowFlags wFlags):
    QChart(QChart::ChartTypeCartesian, parent, wFlags),
    m_series(0),
    m_axis(new QValueAxis),
    m_step(0),
    m_x(5),
    m_y(1)
{
    QObject::connect(&m_timer, &QTimer::timeout, this, &UXDL::handleTimeout);
    m_timer.setInterval(500);

    m_series = new QSplineSeries(this);
    m_series->setName("Input Data");
    QPen green(QColor(123,203,94));
    green.setWidth(1);
    m_series->setPen(green);
    m_series->append(m_x, m_y);

    addSeries(m_series);

    setPlotAreaBackgroundBrush(QBrush(QColor("#4a484d")));
    setPlotAreaBackgroundVisible(true);

    setBackgroundBrush(QBrush(QColor("74,74,74")));

//    QFont labelsFont;
//    labelsFont.setPixelSize(12);
//    axisX()->setLabelsFont(labelsFont);
//    axisY()->setLabelsFont(labelsFont);

//    // Customize axis colors
//    QPen axisPen(QRgb(0xd18952));
//    axisPen.setWidth(2);
//    axisX()->setLinePen(axisPen);
//    axisY()->setLinePen(axisPen);

//    // Customize axis label colors
//    QBrush axisBrush(Qt::white);
//    axisX()->setLabelsBrush(axisBrush);
//    axisY()->setLabelsBrush(axisBrush);

//    // Customize grid lines and shades
//    axisX()->setGridLineVisible(true);
//    axisY()->setGridLineVisible(true);
//    axisX()->setGridLineColor(QColor(255,255,255,70));
//    axisY()->setGridLineColor(QColor(255,255,255,70));




//    createDefaultAxes();

    QValueAxis *maxisY = new QValueAxis;

    QFont labelsFont;
    labelsFont.setPixelSize(12);
    m_axis->setLabelsFont(labelsFont);
    maxisY->setLabelsFont(labelsFont);

    // Customize axis colors
    QPen axisPen(QColor(255,255,255,70));
    axisPen.setWidth(2);
    m_axis->setLinePen(axisPen);
    maxisY->setLinePen(axisPen);

    // Customize axis label colors
    QBrush axisBrush(Qt::white);
    m_axis->setLabelsBrush(axisBrush);
    maxisY->setLabelsBrush(axisBrush);

    // Customize grid lines and shades
    m_axis->setGridLineVisible(true);
    maxisY->setGridLineVisible(true);
    m_axis->setGridLineColor(QColor(255,255,255,70));
    maxisY->setGridLineColor(QColor(255,255,255,70));





    createDefaultAxes();

    setAxisX(m_axis, m_series);
    setAxisY(maxisY,m_series);
    m_axis->setGridLineColor(QColor(255,255,255,70));
    axisY()->setGridLineColor(QColor(255,255,255,70));


    axisY()->setLabelsFont(labelsFont);
    axisY()->setLinePen(axisPen);
    axisY()->setLabelsBrush(axisBrush);

    m_axis->setTickCount(5);
    m_axis->applyNiceNumbers();


    axisX()->setRange(0, 10);
    axisY()->setRange(-5, 10);

    m_timer.start();
}

UXDL::~UXDL()
{

}

void UXDL::handleTimeout()
{
    qreal x = plotArea().width() / m_axis->tickCount();
    qreal y = (m_axis->max() - m_axis->min()) / m_axis->tickCount();
    m_x += y;
    m_y = QRandomGenerator::global()->bounded(5) - 2.5;
//    qDebug() << "m_x:" << m_x << " " << "m_y:" << m_y;
    m_series->append(m_x, m_y);
    scroll(x, 0);
    if (m_x == 100)
        m_timer.stop();
}

