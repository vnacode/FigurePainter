#include "figure.h"
#include <QPainter>

Figure::Figure(QPointF point, QObject *parent) :
    QObject(parent)
{
    this->setStartPoint(mapFromScene(point));
    this->setEndPoint(mapFromScene(point));
    connect(this, &Figure::pointChanged, this, &Figure::updateRomb);

    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::LeftButton);
    setAcceptDrops(true);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setPen(getDefaultPen());
    setBrush(QBrush(Qt::transparent));
}

QRectF Figure::boundingRect() const
{
    return QRectF((endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) - 5,
                  (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) - 5,
                  qAbs(endPoint().x() - startPoint().x()) + 10,
                  qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Figure::setSelectionHighlight(bool selected)
{
    setPen(selected ? QPen(QColor(0,0,0),4,Qt::DashLine) : getDefaultPen());
}

void Figure::updateRomb()
{
    this->update(boundingRect());
}


void Figure::setStartPoint(const QPointF point)
{
    m_startPoint = point;
    emit pointChanged();
}

void Figure::setEndPoint(const QPointF point)
{
    m_endPoint = point;
    emit pointChanged();
}

void Figure::setPen(const QPen &pen)
{
    m_pen = pen;
    emit colorChanged();
}

void Figure::setBrush(const QBrush &brush)
{
    m_Brush = brush;
    emit colorChanged();
}

QVariant Figure::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == QGraphicsItem::ItemSelectedChange) {

        emit selectedChanged(value.toBool());
        setSelectionHighlight(value.toBool());
    }
    return value;
}


QPointF Figure::startPoint() const
{
    return m_startPoint;
}

QPointF Figure::endPoint() const
{
    return m_endPoint;
}

QPen Figure::pen()
{
    return  m_pen;
}

QBrush Figure::brush() const
{
    return  m_Brush;
}

QPointF Figure::center() const
{
    return boundingRect().center();
}
