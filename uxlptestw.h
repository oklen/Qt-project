#ifndef UXLPTESTW_H
#define UXLPTESTW_H

#include <QWidget>
#include "components/qtmaterialautocomplete.h"
#include "components/qtmaterialraisedbutton.h"
#include <QPushButton>
#include <QBoxLayout>
#include <QDebug>
#include <QPaintEvent>
#include "uxlp.h"

class UXLPTESTW : public QWidget
{
    Q_OBJECT
public:
    explicit UXLPTESTW(QWidget *parent = nullptr);
    ~UXLPTESTW();

    void paintEvent(QPaintEvent *event);
    QtMaterialAutoComplete a1;
    QtMaterialAutoComplete a2;
    QtMaterialRaisedButton *ok;
    QVBoxLayout v2layout;
    QHBoxLayout hlayout;
    UXLP lp;


signals:

public slots:
    void updatelp();
};

#endif // UXLPTESTW_H
