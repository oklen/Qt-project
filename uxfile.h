#ifndef UXFILE_H
#define UXFILE_H

#include <QWidget>
#include <QFile>
#include <QDebug>

//Performance the file stringlist IO

class UXFILE : public QWidget
{
    Q_OBJECT
public:
    explicit UXFILE(QWidget *parent = nullptr);
    QStringList read();
    void write(QStringList& list);

signals:

public slots:
};

#endif // UXFILE_H
