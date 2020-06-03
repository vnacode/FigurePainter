#include "ellipse.h"
#include <QPainter>



Ellipse::Ellipse(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

QRectF Ellipse::boundingRect() const
{
    QRectF rect(startPoint().x() - qAbs(endPoint().x() - startPoint().x()),
                startPoint().y()  - qAbs(endPoint().y() - startPoint().y()),
                 2 * qAbs(endPoint().x() - startPoint().x()) + 10,
                 2 * qAbs(endPoint().y() - startPoint().y()) + 10);
    return  rect;
}

void Ellipse::setSelectionHighlight(bool selected)
{
    setPen(selected ? QPen(QColor(0,180,50),2) : QPen(QColor(0,0,230),2));
}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen());
    painter->setBrush(brush());
    QPointF center(endPoint() - startPoint());
    painter->drawEllipse(QPointF(startPoint().x(),startPoint().y()),center.x(),center.y());

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
