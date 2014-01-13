#ifndef ILAMP_H
#define ILAMP_H


class ILamp
{
public:
    virtual void switchOn()=0;
    virtual void switchOff()=0;
    virtual void changeColor(QColor& color)=0;
};

#endif
