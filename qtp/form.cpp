#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setName("Google");
    connect(ui->checkBox, &QPushButton::clicked, this, &Form::rename);
    connect(ui->pushButton_2, &QPushButton::clicked,
            [this]{
       Form::removed(this);
    });
}

Form::~Form()
{
    delete ui;
}

void Form::setName(const QString &name)
{
    ui->checkBox->text();
}

QString Form::name() const
{
    return ui->checkBox->text();
}

bool Form::isCompleted() const
{
    return ui->checkBox->isChecked();
}

void Form::rename()
{
    bool ok;
    QString value = QInputDialog::getText(this, tr("Edit task"),
                                          tr("task name"),
                                          QLineEdit::Normal,
                                          this->name(),
                                          &ok);
    if (ok && !value.isEmpty()){
        setName(value);
    }
}
