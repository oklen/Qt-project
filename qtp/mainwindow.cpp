#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <form.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    Form form;
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked,
            this, &MainWindow::addTask);
    connect(ui->pushButton_4,&QPushButton::clicked, this, &MainWindow::sub);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    bool ok;
    QString name = QInputDialog::getText(this, tr("Add task"),
                                         tr("Task Name"),
                                         QLineEdit::Normal,
                                         tr("Untitled task"), &ok);
    if (ok && !name.isEmpty()){
        qDebug() << "Adding new task";
    }
    qDebug() << "Add Task ";
    Form* task = new Form;
    mTasks.append(task);
    ui->horizontalLayout->addWidget(task);
    ui->label->setText("Google:" + QString::number(mTasks.length()));
    qDebug() << mTasks.length();
}

void MainWindow::sub()
{
    int num = ui->label->text().split(":")[1].toInt();
    ui->label->setText(QString::number(num));
}
