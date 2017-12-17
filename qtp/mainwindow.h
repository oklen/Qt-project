#include <QDebug>
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QVector>

#include "form.h"
#include <QInputDialog>
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addTask();
    void sub();

private:
    Ui::MainWindow *ui;
    QVector<Form*> mTasks;
};

#endif // MAINWINDOW_H
