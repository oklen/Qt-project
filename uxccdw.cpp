#include "uxccdw.h"

UXCCDW::UXCCDW(QWidget *parent) : QWidget(parent)
{
    setFixedSize(1392/1.65,1040/1.65);
//    connect(this,SIGNAL(objectNameChanged(QString)),this,SLOT(repaint()));
    connect(this,SIGNAL(shoudld()),this,SLOT(update()));
    mpen.setWidth(1);
    mpen.setColor(Qt::white);
//    QLabel currentp;
//    QLabel remaintime;
//    QFont serifFont("Times", 20, QFont::Bold);
//    currentp.setFont(serifFont);
//    remaintime.setFont(serifFont);
//    currentp.setParent(this);
//    remaintime.setParent(this);
//    currentp.setText("75% (256 of 192)");
//    remaintime.setText("~ 00:15:00");
//    currentp.move(20,460);
//    remaintime.move(440,460);
    progress.setParent(this);
    progress.setInvertedAppearance(true);
    progress.setProgressType(Material::DeterminateProgress);
    progress.setMinimum(0);
    progress.setMaximum(100);
    progress.setValue(75);
    progress.setFixedSize(300,20);
    progress.move(10,480+130);
    progress.setBackgroundColor(QColor(0,0,0,20));
    progress.setProgressColor(QColor(240,240,240,250));

    cp.setText(QString::fromLocal8Bit("75% (192 of 256)"));
    cp.setFont(QFont("Times", 25, QFont::Bold));
    rt.setText(" 00:15:00");
    intensity.setText("Intensity 1.0V");

    intensity.move(width()-110,120);
    cp.move(20,460+130);
    rt.move(1392/1.65-100,1040/1.65-30);

    rt.setParent(this);
    cp.setParent(this);
    intensity.setParent(this);

    cp.setObjectName("currentprocesslabel");
    rt.setObjectName("remaintime");
    intensity.setObjectName("intensity");

    cp.raise();
    rt.raise();
    setStyleSheet("QLabel{background:(0,0,0,0)}"
                  "QLabel#currentprocesslabel{color:white;font-size:18px;}"
                  "QLabel#remaintime{color:white;font-size:19px;}"
                  "QLabel#intensity{color:white;font-size:14px;}");

    cp.setAttribute(Qt::WA_TranslucentBackground);
    rt.setAttribute(Qt::WA_TranslucentBackground);
    intensity.setAttribute(Qt::WA_TranslucentBackground);


    ub.setParent(this);
    ub.move((1392/1.65-ub.width())/2,1040/1.65-ub.height());
    ud.setParent(this);
    ud.move((1392/1.65-ud.width())/2,0);
    ul.setParent(this);
    ul.move(0,(1040/1.65-ul.height())/2);
    ur.setParent(this);
    ur.move(1392/1.65-ur.width(),(1040/1.65-ul.height())/2);

    lp.move(this->width()-lp.width()-10,10);
    lp.setParent(this);
}

void UXCCDW::paintEvent(QPaintEvent *event)
{
//    if(!dataarray)
//    qDebug() << "the should close is " << shouldclose;
    if(!toggle)
        return;
    else
        qDebug() << "Draw!";
    QPainter mpainter;
//    mpainter.setRenderHint(QPainter::Antialiasing);
    mpainter.begin(this);
    uchar *cache = dataarray;

    if(!zoom)
    mpainter.drawPixmap(0,0,1392/1.65,1040/1.65,
                        QPixmap::fromImage
                        (QImage(cache,1392,1040,QImage::Format_RGB888))
                        .scaled(1392/1.65,1040/1.65));
    else
        mpainter.drawPixmap(0,0,1392/1.65,1040/1.65,
                            QPixmap::fromImage
                            (QImage(cache,1392,1040,QImage::Format_RGB888))
                            ,initpoint.x()*1.65,
                            initpoint.y()*1.65,
                            (endpoint-initpoint).x()*1.65,(endpoint-initpoint).y()*1.65);
    if(mousedown)
    {
        mpainter.setPen(mpen);
        mpainter.drawRect(QRect(initpoint,curpoint));
    }
    //    qDebug() << "Draw done!";
    mpainter.end();
}

void UXCCDW::doupdate()
{
    if(!shouldclose)
        {
    emit shoudld();
//        *progresspix = progress.grab(progress.rect());
        }
}

void UXCCDW::mousePressEvent(QMouseEvent *event)
{
//    if(!shouldclose)
//    shouldclose = true;
//    else
//        shouldclose = false;
//    qDebug() << "the should close is " << shouldclose;
    if(event->button() == Qt::RightButton)
    {zoom = false;
    return;}
    initpoint = event->pos();
    curpoint =event->pos();
    mousedown = true;
}

void UXCCDW::mouseMoveEvent(QMouseEvent *event)
{
    curpoint = event->pos();
}

void UXCCDW::mouseReleaseEvent(QMouseEvent *event)
{
    endpoint = event->pos();
    mousedown =false;
    if(event->button() == Qt::RightButton || (initpoint-endpoint).manhattanLength()<10)
    {
        return;
    }
    zoom = true;
}
void UXCCDW::stoppaint()
{
    bstoppaint = true;
}

void UXCCDW::set4window(float up, float left, float sum)
{
    lp.inputx = left;
    lp.inputy = up;
    lp.update();
    intensity.setText(QString::number(sum));
}
