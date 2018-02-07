#include "ux3dw.h"
#include <QStyle>

UX3DW::UX3DW(QWidget *parent) : QFrame(parent),
    colorbar{new QLabel},h3layout{new QHBoxLayout},
    toggle{new QtMaterialToggle},
    chart(new UXZOOMCHART),
    chartview(new UXZOOMCHARTVIEW(0)),
    selector{new UXWidget},
  pointer{new QWidget},
  d3replacer{new QLabel}

{
    chartview = new UXZOOMCHARTVIEW(selector->getchart());
    chartview->yvalue = selector->vectorz;
    chartview->enablevis();

    this->setStyleSheet("QFrame{background-color: #4c4c4c; border: none;"
                        "border-radius: 5px;"
                        "border: 0px solid white;}"
                        "QLabel{color:white;font-size:15px}"
                        "QLabel#d3label{font-size:25px}");

    this->setFrameStyle(QPalette::Shadow);

//    this->setPalette(pa);

    QHBoxLayout *h2layout = new QHBoxLayout;
    QLabel *d3label = new QLabel;
    d3label->setObjectName("d3label");


    QFont font;
    font.setPointSize(15);
    this->setFont(font);
    font.setPointSize(20);
    d3label->setFont(font);

//    setStyleSheet("*{background:black }"
//                  "Frame{border:3px}");



    QWidget *container = QWidget::createWindowContainer(graph,
                                                        this,
                                                        Qt::SubWindow);
    pointer = container;

    modifier = new UXDatav(graph);

//graph->scene()->activeCamera()->setCameraPosition(m_xRotation, m_yRotation);


    d3label->setText("3D Modeling");
    QtMaterialIconButton *max = new QtMaterialIconButton
            (QIcon("./components/icons/navigation/svg/production/ic_expand_more_24px.svg"));
    QtMaterialIconButton *close = new QtMaterialIconButton
            (QIcon("./components/icons/navigation/svg/production/ic_close_24px.svg"));
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
    colorbar->setPixmap(*pix);
    colorbar->setFixedSize(QSize(50,400));
    container->setFixedSize(QSize(500,400));
        h1layout->addWidget(colorbar);
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
    zoomlabel->setText("Zoom");
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
//    v2layout->addWidget(selector);

//dynamic widget

    h3layout->addLayout(v1layout);
//    h3layout->addWidget(chartview);
    setLayout(v2layout);

    // Add Connect there


    connect(modifier->getgraph()->seriesList().at(0),&QSurface3DSeries::selectedPointChanged,
                     this,&UX3DW::setxyz);
    connect(toggle,SIGNAL(toggled(bool)),this,SLOT(changetoggle(bool)));
    connect(max,SIGNAL(clicked()),this,SLOT(showMaximized()));
    connect(close,SIGNAL(clicked()),this,SLOT(close()));
    connect(xslider,SIGNAL(valueChanged(int)),this,SLOT(rotatex(int)));
    connect(yslider,SIGNAL(valueChanged(int)),this,SLOT(rotatey(int)));
    connect(zoomslider,SIGNAL(valueChanged(int)),this,SLOT(zoomto(int)));

    // Custom 3D Theme
    Q3DTheme *mytheme = new Q3DTheme;
    mytheme = graph->activeTheme();
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
    if(!pointer->isVisible())
    {
            raise();
            d3replacer->hide();
            pointer->show();
    }
    mousedown = true;
    hotpot = event->pos();

}

void UX3DW::mouseReleaseEvent(QMouseEvent *event)
{

    qDebug() << "Child Release";
    mousedown = false;
}

void UX3DW::mouseMoveEvent(QMouseEvent *event)
{
    if (mousedown && QRect(0,0,1000,800).contains(this->pos()+event->pos()-hotpot)){
        qDebug() << "Move!";
        this->move(this->pos()+event->pos()-hotpot);
    }
    else
    {
        if(mousedown && QRect(0,0,1000,800).contains(this->pos()
                                                     +QPoint((event->pos()-hotpot).x(),0)))
            this->move(this->pos()+QPoint((event->pos()-hotpot).x(),0));
        if(mousedown && QRect(0,0,1000,800).contains(this->pos()
                                                     +QPoint(0,(event->pos()-hotpot).y())))
            this->move(this->pos()+QPoint(0,(event->pos()-hotpot).y()));
    }
    qDebug() << "this pos:" << this->pos() << " "
             << "event pos:" << event->pos() << " "
             << "hotpot:" << hotpot;
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
    QPoint d3point = modifier->getgraph()->selectedSeries()->selectedPoint();
    selector->manualactive(d3point);
    qDebug() << "Detected " << d3point;
}

void UX3DW::hidechart()
{
    h3layout->removeWidget(chartview);
    chartview->hide();
    this->adjustSize();
}

void UX3DW::enablechart()
{
    h3layout->addWidget(chartview);
    chartview->setFixedSize(600,700);
//    chartview->chart()->resize(QSize(300,300));
    chartview->show();
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
    xr = rotation;
    modifier->getgraph()->scene()->activeCamera()->setCameraPosition(xr,yr,zoom);
    qDebug() << "Change x:" << xr;
}

void UX3DW::rotatey(int rotation)
{
    yr = rotation;
    modifier->getgraph()->scene()->activeCamera()->setCameraPosition(xr,yr,zoom);
    qDebug() << "Change y:" << yr;
}

void UX3DW::zoomto(int zoomin)
{
    zoom = zoomin;
    modifier->getgraph()->scene()->activeCamera()->setCameraPosition(xr,yr,zoom);
}

void UX3DW::windowswap()
{
    if(pointer->isVisible())
    {
        QScreen *screen = QGuiApplication::primaryScreen();
        QPixmap mypix(screen->grabWindow(mainwindowid,this->x()+pointer->x(),
                                         this->y()+pointer->y(),pointer->width(),
                                         pointer->height()));
        d3replacer->setPixmap(mypix);
        graph->requestUpdate();

        pointer->hide();
        h1layout->addWidget(d3replacer);
        d3replacer->show();
//        h1layout->addWidget(pointer);
//        pointer->hide();
//        QTimer::singleShot(5000,this,SLOT(hided3()));
        //        colorbar->hide();
        adjustSize();
//        qDebug() << "paint hide!";
    }
}

void UX3DW::hided3()
{
    h1layout->removeWidget(pointer);
    pointer->hide();
}
