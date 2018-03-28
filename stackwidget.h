#ifndef STACKWIDGET_H
#define STACKWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <QDrag>
#include <QMimeData>
#include <QPushButton>


QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE


class Stackwidget : public QPushButton
{
    Q_OBJECT
public:
    explicit Stackwidget(QWidget *parent = nullptr);
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    QPoint startpoint {0,0};

signals:

public slots:
};

#endif // STACKWIDGET_H
