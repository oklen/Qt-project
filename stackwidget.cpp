#include "stackwidget.h"
#include <QWindow>
#include <QDebug>

Stackwidget::Stackwidget(QWidget *parent) : QPushButton(parent)
{
    setAcceptDrops(true);
    QWidget *push = new QWidget(this);
        push->setParent(this);
            push->setAttribute(Qt::WA_DeleteOnClose);
    qDebug() << "Father " << push->parent() << "  " << push->pos();

    push->setAcceptDrops(true);
    push->show();

}

void Stackwidget::dragEnterEvent(QDragEnterEvent *event)
{

    event->setDropAction(Qt::MoveAction);
    event->acceptProposedAction();
}

void Stackwidget::dropEvent(QDropEvent *event)
{
    QWidget *child = static_cast<QWidget*>(children().at(0));
    QPoint adjust =  child->pos();
    child->move(event->pos() - adjust);
}

void Stackwidget::mousePressEvent(QMouseEvent *event)
{
    QPoint hotSpot = event->pos();
    QWidget *child = static_cast<QWidget*>(childAt(event->pos()));
//    qDebug() << child->pos() << "  " << event->pos();
    if(!child){
        return;
    }
    else
        child->move(0,10);
    QPixmap pixmap = QWidget::grab(QRect(child->x(),child->y(),child->width(),child->height()));

    QMimeData *mimeData = new QMimeData;

    QDrag *drag = new QDrag(child);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(hotSpot);

    Qt::DropAction dropAction = drag->start(Qt::CopyAction | Qt::MoveAction);
}

void Stackwidget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget *child = static_cast<QWidget*>(children().at(0));
    child->move(event->pos());
}
