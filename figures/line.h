#ifndef LINE_H
#define LINE_H

#include <QObject>

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Line : public Figure
{
    Q_OBJECT

public:
    explicit Line(QPointF point, QObject *parent = 0);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // LINE_H
