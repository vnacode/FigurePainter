
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PaintFigure
TEMPLATE = app

INCLUDEPATH += figures

SOURCES += main.cpp\
    figures/ellipse.cpp \
        mainwindow.cpp \
    paintscene.cpp \
    figures/triangle.cpp \
    figures/square.cpp \
    figures/romb.cpp \
    figures/figure.cpp

HEADERS  += mainwindow.h \
    figures/ellipse.h \
    figures/triangle.h \
    figures/square.h \
    figures/romb.h \
    figures/paintscene.h \
    figures/figure.h

FORMS    += mainwindow.ui
