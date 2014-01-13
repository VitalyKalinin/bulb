#include <QDebug>
#include "action.h"

Action::Action(QByteArray& data)
{
    this->data=data;
}


void Action::run(ILamp* lamp)
{
    qDebug()<<"Nothing to do";
}


LightOnAction::LightOnAction(QByteArray& data):
    Action(data)
{
}

void LightOnAction::run(ILamp* lamp)
{
    qDebug()<<"ON from Action";
    lamp->switchOn();
}

LightOffAction::LightOffAction(QByteArray& data):
    Action(data)
{
}

void LightOffAction::run(ILamp* lamp)
{
    qDebug()<<"OFF from Action";
    lamp->switchOff();
}

ChangeColorAction::ChangeColorAction(QByteArray& data):
    Action(data)
{
    qDebug()<<"R:"<<quint8(data[0]);
    qDebug()<<"G:"<<quint8(data[1]);
    qDebug()<<"B:"<<quint8(data[2]);
    QColor colorFromData=QColor(quint8(data[0]),quint8(data[1]),quint8(data[2]));
    colorFromData.setAlpha(50);
    color=colorFromData;
}


void ChangeColorAction::run(ILamp* lamp)
{
    qDebug()<<"CC from Action";
    lamp->changeColor(color);
}
