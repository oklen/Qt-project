/**********************************************************
**This class contain the CCD ,three scan steps;
** the layout is too tight that some rewrite of the components'
**  size and the layout order is needed to implement.
**
**********************************************************/
#ifndef AUTOP_H
#define AUTOP_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QPainter>
#include <QPixmap>
#include <QLinearGradient>
#include <QLabel>
#include <QSpacerItem>
#include <QPaintEvent>
#include <QVector3D>
#include <QLCDNumber>
#include <QCloseEvent>
#include <QGraphicsItem>
#include <QTimer>

#include "components/qtmaterialiconbutton.h"
#include "components/qtmaterialprogress.h"
#include "components/qtmaterialraisedbutton.h"
#include "components/qtmaterialtoggle.h"
#include "components/qtmaterialslider.h"
#include "components/qtmaterialautocomplete.h"
#include "components/qtmaterialdialog.h"
#include "uxcb.h"
#include "uxccdper.h"
#include "uxlp.h"




class UXAUTOP : public QFrame
{
    Q_OBJECT
public:
    explicit UXAUTOP(QWidget *parent = nullptr);
    QHBoxLayout *h2layout;
    QtMaterialRaisedButton *warning; //raised button to be the interface to show close waring

    void closeEvent(QCloseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    bool showed = false; // if the window is showed
    bool ch = true;
    QVBoxLayout *v3layout = new QVBoxLayout;
    QVBoxLayout *v11layout = new QVBoxLayout;

//    UXLP lp;

private:

    QtMaterialRaisedButton *begin = new QtMaterialRaisedButton; //
    QtMaterialRaisedButton *end = new QtMaterialRaisedButton; //probe come back
    QtMaterialRaisedButton *approache = new QtMaterialRaisedButton; //进针
    QTimer *invoker = new QTimer; //用来激活扫描进度刷新的时钟
    bool approchbegin = false; // if 进针 begin
    bool beginbegin = false; // if  扫描 begin
    bool endbegin = false; // if 退针 begin

    QPoint hotpot = QPoint(0,0); // mouse click point relativtly its parent
    bool mousedown = false; // if mouse button pressed

signals:
    void bepressed(); //Signal to tell the mousepresse d event
public slots:
    void approchestart();
    void beginstart();
    void endstart();
    void closehide();
};

#endif // AUTOP_H
