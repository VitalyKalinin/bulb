/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "mylamp.h"

#include <QtGui>

#include <math.h>

Lamp::Lamp():
    mState(false),
    serverColour(QColor(255,1,255))
{
}

MyLampView::MyLampView(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(300, 250);
    setWindowTitle(tr("MyLamp"));

    lamp.serverColour.setAlpha(50);
}

void MyLampView::switchOn()
{
    qDebug()<<"Light ON";
    lamp.mState=true;
    update();
}

void MyLampView::switchOff()
{
    qDebug()<<"Light Off";
    lamp.mState=false;
    update();
}

void MyLampView::changeColor(QColor& color)
{
    qDebug()<<"Change Color";
    lamp.serverColour=color;
    update();
}

 void MyLampView::paintEvent ( QPaintEvent * event )
{
    QPen pen;

    QPainter painter(this);

    //QString fileName = "/home/pike/Bulb/art.png";
    QString fileName = ":/MyFiles/art.png";
    QPixmap temp;
    if (temp.load(fileName) == false)
    {
        QMessageBox mb(this);
        QString qs("Failed to load " + fileName);
        mb.setText(qs);
        mb.exec();
    }
    painter.drawPixmap(0, 0, temp);

    if(lamp.mState==false)
        return;
    painter.setPen(pen);
    QBrush brush=Qt::SolidPattern;
    brush.setColor(lamp.serverColour);
    painter.setBrush(brush);
    QPoint point(140,70);
    painter.drawEllipse(point,50,50);
    QWidget::paintEvent(event);
 }
