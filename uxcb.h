#ifndef UXCB_H
#define UXCB_H

#include <QWidget>
#include <QPainter>
#include <QEnterEvent>

class UXCB : public QWidget
{
    Q_OBJECT
public:
    explicit UXCB(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:
    void myclick();
public slots:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    bool mouseenter = false;
};


#endif // UXCB_H
