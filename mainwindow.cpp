#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
//    ui->pushButton->setIcon(QIcon("F:/Qt-project/picture/Brand.png"));
//    m_autop.setParent(this);
//    m_autop.setFixedSize(800,800);
    ui->setupUi(this);

//    ui->widget->deleteLater();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupall()
{
//    ui->widget->v11layout->addWidget(ccdw);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    setupall();
}
