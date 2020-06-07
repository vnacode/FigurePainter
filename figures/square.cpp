#include "square.h"
#include <QPainter>

Square::Square(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

void Square::setSelectionHighlight(bool selected)
{
  setPen(selected ? QPen(QColor(0,0,230),4) : getDefaultPen());
}


void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen());
    painter->setBrush(brush());
    QRectF rect(endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),
                endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),
                qAbs(endPoint().x() - startPoint().x()),
                qAbs(endPoint().y() - startPoint().y()));

    painter->drawRect(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

