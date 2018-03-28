#include "ux3dw.h"
#include <QStyle>
#include <QDebug>


UX3DW::UX3DW(QWidget *parent) : QFrame(parent),
    qlcolorbar{new QLabel},h3layout{new QHBoxLayout},
    toggle{new QtMaterialToggle},
    uxzcchart(new UXZOOMCHART),
    uxzcvchartview(new UXZOOMCHARTVIEW(0)),
    uxwselector{new UXWidget},
  qwpointer{new QWidget},
  qld3replacer{new QLabel}

{
    uxzcvchartview = new UXZOOMCHARTVIEW(uxwselector->getchart());
    uxzcvchartview->yvalue = uxwselector->vectorz;
    uxzcvchartview->enablevis();

    QHBoxLayout *h2layout = new QHBoxLayout;
    QLabel *d3label = new QLabel;
    d3label->setObjectName("d3label");


    QFont font;
    font.setPointSize(15);
    this->setFont(font);
    font.setPointSize(20);
    d3label->setFont(font);

    container = QWidget::createWindowContainer(q3dsgraph,
                                                        this);
    qwpointer = container;

    uxdvmodifier = new UXDatav(q3dsgraph);

//graph->scene()->activeCamera()->setCameraPosition(m_ixrotation, m_iyrotation);


    d3label->setText("3D Modeling");
    QtMaterialIconButton *max = new QtMaterialIconButton
            (QIcon("./components/icons/navigation/svg/production/ic_expand_more_24px.svg"));

    //    QtMaterialIconButton *close = new QtMaterialIconButton(
    //                QIcon("./components/icons/navigation/svg/production/ic_expand_more_24px.svg"));
    UXCB *close = new UXCB(this);
    h2layout->addWidget(d3label);
    h2layout->addStretch();
    h2layout->addWidget(max);
    h2layout->addWidget(close);

//Construct h1

    QLinearGradient *brush = new QLinearGradient(0,0,0.1,400);
    brush->setColorAt(1.0,Qt::blue);
    brush->setColorAt(0.5,Qt::yellow);
    brush->setColorAt(0.0,Qt::red);
    QPixmap *pix = new QPixmap(50,400);
    QPainter *colorbarpainter = new QPainter(pix);
    colorbarpainter->setBrush(QBrush(*brush));
    colorbarpainter->drawRect(QRect(0,0,50,400));
    qlcolorbar->setPixmap(*pix);
    qlcolorbar->setFixedSize(QSize(50,400));
    container->setFixedSize(QSize(500,400));
        h1layout->addWidget(qlcolorbar);
    h1layout->addWidget(container);


//construct h2

    QVBoxLayout *h4layout = new QVBoxLayout;
    QLabel *hrotate = new QLabel;
    hrotate->setText("Horitical Rotate");
    QtMaterialSlider *xslider = new QtMaterialSlider;
    xslider->setMaximum(180);
    xslider->setMinimum(-180);
    xslider->setValue(0);
    h4layout->addWidget(hrotate);
    h4layout->addWidget(xslider);

    QVBoxLayout *h5layout = new QVBoxLayout;
    QLabel *vrotate = new QLabel;
    vrotate->setText("Vertiacl Rotate");
    QtMaterialSlider *yslider = new QtMaterialSlider;
    yslider->setMaximum(90);
    yslider->setMinimum(0);
    yslider->setValue(0);
    h5layout->addWidget(vrotate);
    h5layout->addWidget(yslider);

    QVBoxLayout *h7layout = new QVBoxLayout;
    QLabel *zoomlabel = new QLabel;
    zoomlabel->setText("zoom");
    QtMaterialSlider *zoomslider = new QtMaterialSlider;
    zoomslider->setMinimum(10);
    zoomslider->setMaximum(500);
    zoomslider->setValue(100);
    h7layout->addWidget(zoomlabel);
    h7layout->addWidget(zoomslider);

    QHBoxLayout *h6layout = new QHBoxLayout;
    QLabel *analysize = new QLabel;
    analysize->setText("Slice Analysize");
    QtMaterialToggle *toggle = new  QtMaterialToggle;
    toggle->setCheckable(true);
    toggle->setChecked(false);
    h6layout->addWidget(analysize);
    h6layout->addWidget(toggle);
    h6layout->setAlignment(Qt::AlignLeft);

    QVBoxLayout *v1layout = new QVBoxLayout;
    v1layout->addLayout(h1layout);
    v1layout->addLayout(h4layout);
    v1layout->addLayout(h5layout);
    v1layout->addLayout(h7layout);
    v1layout->addLayout(h6layout);
    v1layout->setAlignment(Qt::AlignTop);

    QVBoxLayout *v2layout = new QVBoxLayout;
    v2layout->addLayout(h2layout);
    v2layout->addLayout(h3layout);

//dynamic widget

    h3layout->addLayout(v1layout);
//    h3layout->addWidget(uxzcvchartview);
    setLayout(v2layout);

    // Add Connect there


    connect(uxdvmodifier->getgraph()->seriesList().at(0),&QSurface3DSeries::selectedPointChanged,
                     this,&UX3DW::setxyz);
    connect(toggle,SIGNAL(toggled(bool)),this,SLOT(changetoggle(bool)));
    connect(max,SIGNAL(clicked()),this,SLOT(showMaximized()));
    connect(close,SIGNAL(myclick()),this,SLOT(closehide()));
    connect(xslider,SIGNAL(valueChanged(int)),this,SLOT(rotatex(int)));
    connect(yslider,SIGNAL(valueChanged(int)),this,SLOT(rotatey(int)));
    connect(zoomslider,SIGNAL(valueChanged(int)),this,SLOT(zoomto(int)));

    //set format
    setqss("F:/Qt-project/picture/3d.qss");
    this->setFrameStyle(QPalette::Shadow);

    // Custom 3D Theme
    Q3DTheme *mytheme = new Q3DTheme;
    mytheme = q3dsgraph->activeTheme();
    mytheme->setBackgroundColor(Qt::black);
    mytheme->setWindowColor(Qt::black);
    QFont myfont;
    myfont.setBold(true);
    myfont.setPointSize(40);
    mytheme->setFont(myfont);
    mytheme->setLabelTextColor(Qt::white);
    mytheme->setLabelBackgroundEnabled(false);
    mytheme->setAmbientLightStrength(1);
    mytheme->setGridLineColor(Qt::black);


}

void UX3DW::mousePressEvent(QMouseEvent *event)
{
    if(!qwpointer->isVisible())
    {
            raise();
            qld3replacer->hide();
            qwpointer->show();
    }
    mousedown = true;
    qphotpot = event->pos();

}

void UX3DW::mouseReleaseEvent(QMouseEvent *event)
{

    qDebug() << "Child Release";
    mousedown = false;
}

void UX3DW::mouseMoveEvent(QMouseEvent *event)
{
    if (mousedown && QRect(0,0,1000,800).contains(this->pos()+event->pos()-qphotpot)){
        qDebug() << "Move!";
        this->move(this->pos()+event->pos()-qphotpot);
    }
    else
    {
        if(mousedown && QRect(0,0,1000,800).contains(this->pos()
                                                     +QPoint((event->pos()-qphotpot).x(),0)))
            this->move(this->pos()+QPoint((event->pos()-qphotpot).x(),0));
        if(mousedown && QRect(0,0,1000,800).contains(this->pos()
                                                     +QPoint(0,(event->pos()-qphotpot).y())))
            this->move(this->pos()+QPoint(0,(event->pos()-qphotpot).y()));
    }
    qDebug() << "this pos:" << this->pos() << " "
             << "event pos:" << event->pos() << " "
             << "qphotpot:" << qphotpot;
}

void UX3DW::paintEvent(QPaintEvent *event)
{

//            QChartView *chartview = new QChartView(chart);
//            chartview->setParent(this);
//            chartview->setGeometry(0,580,600,330);
//            chartview->show();
}

void UX3DW::setxyz()
{
    QPoint d3point = uxdvmodifier->getgraph()->selectedSeries()->selectedPoint();
    uxwselector->manualactive(d3point);
    qDebug() << "Detected " << d3point;
}

void UX3DW::hidechart()
{
    h3layout->removeWidget(uxzcvchartview);
    uxzcvchartview->hide();
    this->adjustSize();
}
void UX3DW::enablechart()
{
    h3layout->addWidget(uxzcvchartview);
    uxzcvchartview->setFixedSize(600,700);
//    uxzcvchartview->chart()->resize(QSize(300,300));
    uxzcvchartview->show();
    this->adjustSize();
}

void UX3DW::changetoggle(bool checked)
{
    if(checked)
        enablechart();
    else
        hidechart();
}

void UX3DW::rotatex(int rotation)
{
    ixr = rotation;
    uxdvmodifier->getgraph()->scene()->activeCamera()->setCameraPosition(ixr,iyr,izoom);
    qDebug() << "Change x:" << ixr;
}

void UX3DW::rotatey(int rotation)
{
    iyr = rotation;
    uxdvmodifier->getgraph()->scene()->activeCamera()->setCameraPosition(ixr,iyr,izoom);
    qDebug() << "Change y:" << iyr;
}

void UX3DW::zoomto(int izoomin)
{
    izoom = izoomin;
    uxdvmodifier->getgraph()->scene()->activeCamera()->setCameraPosition(ixr,iyr,izoom);
}

void UX3DW::windowswap()
{
    if(qwpointer->isVisible())
    {
        qld3replacer->hide();
        QScreen *screen = QGuiApplication::primaryScreen();
        QDesktopWidget *desk = QApplication::desktop();
        qDebug() <<"pos" << desk->pos();
        QPixmap mypix(  screen->grabWindow(0,QWidget::mapToGlobal(QPoint(qwpointer->x(),0)).x(),
                                         QWidget::mapToGlobal(QPoint(0,qwpointer->y())).y(),qwpointer->width(),
                                         qwpointer->height()));
//        QPixmap mypix(desk->grab());
//        qDebug() << "Get Window Id" << q3dsgraph->winId();


        qld3replacer->setPixmap(mypix);
//        q3dsgraph->requestUpdate();

        qwpointer->hide();
        h1layout->addWidget(qld3replacer);
        qld3replacer->show();
//        h1layout->addWidget(qwpointer);
//        qwpointer->hide();
//        QTimer::singleShot(5000,this,SLOT(hided3()));
        //        colorbar->hide();
        adjustSize();
//        qDebug() << "paint hide!";
    }
}

void UX3DW::hided3()
{
    h1layout->removeWidget(qwpointer);
    qwpointer->hide();
}

void UX3DW::setqss(QString filename)
{
    QFile qssfile(filename);
    qssfile.open(QIODevice::ReadOnly | QIODevice::Text);
    setStyleSheet( qssfile.readAll());
    qssfile.close();
}

void UX3DW::closehide()
{
    hide();
    showed = false;
}
