#ifndef UXMOVE_H
#define UXMOVE_H

#include <QWidget>
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>

class UXMOVE
{

public:
    explicit UXMOVE();
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void move(QPoint point);
    void canceldrag();
    QDrag* setdrag();
    bool ondrag = false;
    QPoint hotpot;
    QDrag *savedrag;

};

#endif // UXMOVE_H
