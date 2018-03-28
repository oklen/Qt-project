#ifndef UXCCDW_H
#define UXCCDW_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include <QLabel>
#include <components/qtmaterialprogress.h>

#include <stdint.h>
#include <include/uxccdupb.h>
#include <include/uxccddownb.h>
#include <include/uxccdleftb.h>
#include <include/uxccdrightb.h>
#include <uxlp.h>





class UXCCDW : public QWidget
{
    Q_OBJECT
public:
    explicit UXCCDW(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void doupdate();
    void stoppaint();
    bool drawing = false;

     uint8_t* dataarray = new uint8_t(1447680*3);
    int xcount = 0;
    int ycount = 0;
    QPen mpen;
    bool shouldclose = false;
    bool toggle = false;

    QLabel cp;
    QLabel rt;
    QLabel intensity;
    UXCCDUPB ub;
    UXCCDDOWNB ud;
    UXCCDLEFTB ul;
    uxccdrightb ur;
    UXLP lp;
    QtMaterialProgress progress;

signals:
    void shoudld();
public slots:
    void set4window(float,float,float);
private:
    bool bstoppaint = false;
    QPoint initpoint = QPoint(0,0);
    QPoint endpoint = QPoint(0,0);
    QPoint curpoint = QPoint(0,0);
    bool mousedown;
    bool zoom = false;

};

#endif // UXCCDW_H
