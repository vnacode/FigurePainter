#include "ellipse.h"
#include <QPainter>



Ellipse::Ellipse(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Ellipse::~Ellipse()
{

}

// Реализуем метод отрисовки
void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 2));

    QPointF sizeRect((endPoint().x() - startPoint().x()),(endPoint().y() - startPoint().y()));
    painter->drawEllipse(QPointF(startPoint().x(),startPoint().y()),sizeRect.x(),sizeRect.y());

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
