#ifndef UXCDRAWHELPER_H
#define UXCDRAWHELPER_H

#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QTimer>
#include <QPaintEvent>
#include <QDebug>

class UXCDRAWHELPER : public QWidget
{
    Q_OBJECT
public:
    explicit UXCDRAWHELPER(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void setlinedata(QVector<float>* cache_vector);
    void setpix(QPixmap *pix);

    int y = 0;
    QPixmap *pix2;
private:

    QVector<float> *vector;
};
#endif // UXCDRAWHELPER_H
