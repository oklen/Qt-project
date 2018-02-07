#include "uxforcew.h"

UXFORCEW::UXFORCEW(QWidget *parent) : QFrame(parent),
    colorbar{new QLabel},childchart{new UXZOOMCHARTVIEW(0)},
  toggle{new QtMaterialToggle},
  h2layoutr{new QHBoxLayout},
  hotpot{QPoint(0,0)}
{
    // consturct the widget and layout

    setWindowTitle("Force Imaging");
    toggle->setCheckable(true);
    toggle->setChecked(false);
    toggle->setFixedHeight(40);
//    toggle->setGeometry(QRect(toggle->pos(),QSize(toggle->size().width(),40)));
    colorbar->setFixedSize(50,512);
    QPixmap *pix = new QPixmap(50,512);
    QLinearGradient *color = new QLinearGradient(0,0,0.1,512);
    color->setColorAt(0.0,Qt::red);
    color->setColorAt(1.0,Qt::blue);
    QPainter *mypainter = new QPainter(pix);
    mypainter->setBrush(QBrush(*color));
    mypainter->drawRect(0,0,50,512);
    mypainter->end();
    colorbar->setPixmap(*pix);

    QVBoxLayout *vlayout = new QVBoxLayout;
    QHBoxLayout *h1layout = new QHBoxLayout;
    QVBoxLayout *v1layout = new QVBoxLayout;
    QHBoxLayout *h2layout = new QHBoxLayout;
    h2layoutr = h2layout;
    QHBoxLayout *h3layout = new QHBoxLayout;
    QHBoxLayout *h4layout = new QHBoxLayout;


    // For h1
    QLabel *title = new QLabel;
    title->setObjectName("forcetitle");
    title->setText("Force Imaging");
    QtMaterialIconButton *max = new QtMaterialIconButton
            (QIcon("./components/icons/navigation/svg/production/ic_expand_more_24px.svg"));
    QtMaterialIconButton *close = new QtMaterialIconButton
            (QIcon("./components/icons/navigation/svg/production/ic_close_24px.svg"));
    h1layout->addWidget(title);
    h1layout->addStretch();
    h1layout->addSpacing(300);
    h1layout->addWidget(max);
    h1layout->addWidget(close);
    h1layout->setAlignment(Qt::AlignTop);
    h1layout->setSizeConstraint(QLayout::SetMinimumSize);

    //For h1 end

    //For h3
    UXWidget *focew = new UXWidget;
    focew->setFixedSize(512,512);




    h3layout->addWidget(focew);
    h3layout->addWidget(colorbar);

    //For h3 end

    //For h4
    QtMaterialRaisedButton *begin = new QtMaterialRaisedButton;
//    begin->setText("Begin");
//    begin->setRole(Material::Default);
//    begin->setOverlayStyle(Material::TintedOverlay);
//    begin->setHaloVisible(false);
//    QtMaterialRaisedButton *pause = new QtMaterialRaisedButton;
//    pause->setText("Pause");
//    QtMaterialRaisedButton *stop = new QtMaterialRaisedButton;
//    stop->setText("Stop");

    QLabel *analyizelabel = new QLabel;
    analyizelabel->setText("slice analysize");
    analyizelabel->setObjectName("analysizelabel");
//    QtMaterialRaisedButton *slice = new QtMaterialRaisedButton;
//    slice->setText("Slice Analysize");
    QtMaterialProgress *processbar = new QtMaterialProgress;
    processbar->setMinimumWidth(0);
    processbar->setMaximum(100);
    processbar->setValue(30);
    processbar->setProgressType(Material::DeterminateProgress);

//    h4layout->addWidget(begin);
//    h4layout->addWidget(pause);
//    h4layout->addWidget(stop);
    h4layout->addWidget(analyizelabel);
    h4layout->addWidget(toggle);
    h4layout->addStretch();
    h4layout->addWidget(processbar);

    UXZOOMCHARTVIEW *chartview = new UXZOOMCHARTVIEW(focew->getchart());
    chartview->yvalue = focew->vectorz;
    chartview->enablevis();

    v1layout->addLayout(h3layout);
    v1layout->addLayout(h4layout);

    h2layout->addLayout(v1layout);
    h2layout->addLayout(v1layout);
    childchart = chartview;
    childchart->setFixedSize(600,700);

    vlayout->addLayout(h1layout);
    vlayout->addLayout(h2layout);
    setLayout(vlayout);


    connect(toggle,SIGNAL(toggled(bool)),this,SLOT(changetoggle(bool))); // open chart analysis
    connect(max,SIGNAL(clicked()),this,SLOT(showMaximized())); // max the window
    connect(close,SIGNAL(clicked()),this,SLOT(close())); // close the window


    setStyleSheet("*{background:#4c4c4c }"
                  "Frame{border:3px}"
                  "QLabel#forcetitle{color:white;font-size:25px;}"
                  "QLabel#analysizelabel{color:white;font-size:20px;}");

    //show the drop shadow
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
    effect->setBlurRadius(10);
    effect->setOffset(QPointF(0, 0));
    effect->setColor(QColor(255, 255, 255, 75));
    setGraphicsEffect(effect);

    setMouseTracking(true);

}

void UXFORCEW::paintEvent(QPaintEvent *event)
{


//    QStyleOption opt;
//    opt.init(this);
//    QPainter p(this);
//    style()->drawPrimitive(QStyle::PE_Frame, &opt, &p, this);
}

void UXFORCEW::hidechart()
{
    h2layoutr->removeWidget(childchart);
    childchart->hide();
    this->adjustSize();
}

void UXFORCEW::enablechart()
{
    h2layoutr->addWidget(childchart);
//    childchart->chart()->setFixedSize(QSize(300,300));
    childchart->show();
    this->adjustSize();
}

void UXFORCEW::changetoggle(bool checked)
{
    if(checked)
        enablechart();
    else
        hidechart();
}

void UXFORCEW::mousePressEvent(QMouseEvent *event)
{
    emit bepressed();
    raise();
        mousedown = true;
        hotpot = event->pos();
}

void UXFORCEW::mouseReleaseEvent(QMouseEvent *event)
{

    qDebug() << "Child Release";
    mousedown = false;

}

void UXFORCEW::mouseMoveEvent(QMouseEvent *event)
{
    if (mousedown and QRect(0,0,1000,800).contains(this->pos()+event->pos()-hotpot)){
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


