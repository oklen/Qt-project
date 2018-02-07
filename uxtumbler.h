/*****************************
 * The tumbler implement by
 * myself
 * ****************************/
#ifndef UXTUMBLER_H
#define UXTUMBLER_H

#include <QWidget>
#include <QBrush>
#include <QPen>
#include <QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QTime>
#include <QTimer>

class UXTUMBLER : public QWidget
{
    Q_OBJECT
public:
    explicit UXTUMBLER(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event); //used to paint the tumbler according curval

    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void setmaxvalue(qreal max); // set the tumbler max value
    void setminvalue(qreal min); // set the tumbler min value
    qreal getcurval();


    QTime mtime;
    QPoint initpoint = QPoint(0,0); // pos the tumbler begin be rotate
    QPoint curpoint = QPoint(0,0); // the tumbler current position
    QPoint lastpos = QPoint(0,0); // to record the last positin before mouse release
    qreal curval = 50.0;
    qreal stayval = 50.0;
    qreal mspeed; // used to record the current tumbler speed
    QTimer *timer = new QTimer;
    int lasttime = 0; // store the moving used time for calculate speed
//    bool shoulddraw = false;
    bool speedinfluent = false; // bool value to tell show whether perform whether influence
//    bool shouldclose = false;
private:
    int maxbound = 500;
    int minbound = 1;

signals:

public slots:
    void interf(); //slot to make the tumbler moving close to the intergal value
};

#endif // UXTUMBLER_H
