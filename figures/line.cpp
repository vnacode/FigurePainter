#include "line.h"
#include <QPainter>



Line::Line(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen());
    painter->setBrush(brush());
    painter->drawLine(startPoint(),endPoint());

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

