#ifndef UXSERVERMESSAGEEMITER_H
#define UXSERVERMESSAGEEMITER_H

#include <QWidget>

class UXSERVERMESSAGEEMITER : public QWidget
{
    Q_OBJECT
public:
    explicit UXSERVERMESSAGEEMITER(QWidget *parent = nullptr);
    void dom1(std::vector<std::string>);
    void dom2(std::vector<std::string>);
    void dom3(std::vector<std::string>);
    void dom4(std::vector<std::string>);
    void dom5(std::vector<std::string>);
    void dom6(std::vector<std::string>);
signals:
    void m1(float,float,float);
    void m2(float,float,float,float,float,float);
    void m3();
    void m4();
    void m5(float,float,float);
    void m6(float,float,float);

public slots:

};

#endif // UXSERVERMESSAGEEMITER_H
