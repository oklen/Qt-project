#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include "uxautop.h"
#include "uxccdper.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *event);
    ~MainWindow();
    UXAUTOP m_autop;
    UXCCDW *ccdw;
    Ui::MainWindow *ui;


private:

public slots:
    void setupall();
};

#endif // MAINWINDOW2_H
