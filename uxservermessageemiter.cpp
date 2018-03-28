#include "uxservermessageemiter.h"

UXSERVERMESSAGEEMITER::UXSERVERMESSAGEEMITER(QWidget *parent) : QWidget(parent)
{

}

void UXSERVERMESSAGEEMITER::dom1(std::vector<std::string> result)
{
    emit m1(atof(result.at(0).c_str()),atof(result.at(1).c_str()),atof(result.at(2).c_str()));
}

void UXSERVERMESSAGEEMITER::dom2(std::vector<std::string> result)
{
    emit m2(atof(result.at(0).c_str()),atof(result.at(1).c_str()),atof(result.at(2).c_str()),
                   atof(result.at(3).c_str()),atof(result.at(4).c_str()),atof(result.at(5).c_str()));
}

void UXSERVERMESSAGEEMITER::dom3(std::vector<std::string> result)
{
    emit m3();
}

void UXSERVERMESSAGEEMITER::dom4(std::vector<std::string> result)
{
    emit m4();
}

void UXSERVERMESSAGEEMITER::dom5(std::vector<std::string> result)
{
    emit m5(atof(result.at(0).c_str()),atof(result.at(1).c_str()),atof(result.at(2).c_str()));
}

void UXSERVERMESSAGEEMITER::dom6(std::vector<std::string> result)
{
    emit m6(atof(result.at(0).c_str()),atof(result.at(1).c_str()),atof(result.at(2).c_str()));
}
