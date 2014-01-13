#ifndef ACTION_H
#define ACTION_H

#include <QByteArray>
#include <QColor>

#include "ilamp.h"

class Action
{
public:
    Action(QByteArray& data);
    virtual void run(ILamp* lamp);
protected:
    QByteArray data;
};


class LightOnAction: public Action
{
public:
    LightOnAction(QByteArray& data);
    virtual void run(ILamp* lamp);
};

class LightOffAction: public Action
{
public:
    LightOffAction(QByteArray& data);
    virtual void run(ILamp* lamp);
};

class ChangeColorAction: public Action
{
public:
    ChangeColorAction(QByteArray& data);
    virtual void run(ILamp* lamp);
protected:
    QColor color;
};

#endif // ACTION_H
