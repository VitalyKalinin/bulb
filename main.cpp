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

#include <QApplication>

#include "client.h"

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>

#include "mylamp.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MyLampView *lamp = new MyLampView();

    QMainWindow mainWindow;
    mainWindow.setCentralWidget(lamp);

    /*QVBoxLayout *vlay = new QVBoxLayout(lamp);
    //QWidget * wdg = new QWidget(widget);
    QPushButton *btn1 = new QPushButton("Bulb ON");
    vlay->addWidget(btn1);
    QPushButton *btn2 = new QPushButton("Bulb OFF");
    vlay->addWidget(btn2);
    QPushButton *btn3 = new QPushButton("Change Color");
    vlay->addWidget(btn3);*/

    /*QObject::connect(btn1, SIGNAL(clicked()), widget, SLOT(onBulbOn()));
    QObject::connect(btn2, SIGNAL(clicked()), widget, SLOT(onBulbOff()));
    QObject::connect(btn3, SIGNAL(clicked()), widget, SLOT(onChangeColor()));*/

       Client client;
       client.setView(lamp);
       client.show();
#if defined(Q_OS_SYMBIAN) || defined(Q_WS_MAEMO_5)
//    mainWindow.menuBar()->addAction("Shuffle", widget, SLOT(shuffle()));
//    mainWindow.menuBar()->addAction("Zoom In", widget, SLOT(zoomIn()));
//    mainWindow.menuBar()->addAction("Zoom Out", widget, SLOT(zoomOut()));
    mainWindow.showMaximized();
#else
    mainWindow.show();
#endif
    return app.exec();
}

