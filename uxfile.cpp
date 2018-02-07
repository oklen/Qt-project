#include "uxfile.h"

UXFILE::UXFILE(QWidget *parent) : QWidget(parent)
{

}

void UXFILE::write(QStringList &list)
{
    QFile mfile("/media/root/LENOVO/computer13/store.txt");
    mfile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&mfile);
    for (auto x:list)
    {
        qDebug() << "write " << x;
        out  << x + "\n";
    }
    mfile.close();
}

QStringList UXFILE::read()
{
    QFile mfile("/media/root/LENOVO/computer13/store.txt");
    mfile.open(QIODevice::ReadOnly | QIODevice::Text);
    QStringList mlist;
    QTextStream in(&mfile);
    while (!in.atEnd()) {
        mlist.append(in.readLine());
    }
    mfile.close();
    return mlist;
}
