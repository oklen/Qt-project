#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QString>
#include <QInputDialog>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

    void setName(const QString& name);
    QString name() const;
    bool isCompleted() const;


public slots:
    void rename();

// It will raise complicated error if your declare signals to public
signals:
    void removed(Form* form);

private:
    Ui::Form *ui;
};

#endif // FORM_H
