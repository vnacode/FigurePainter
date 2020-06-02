#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QPen>
#include <QBrush>

class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF startPoint
               READ startPoint WRITE setStartPoint
               NOTIFY pointChanged)
    Q_PROPERTY(QPointF endPoint
               READ endPoint WRITE setEndPoint
               NOTIFY pointChanged)
    Q_PROPERTY(QPen pen
               READ pen WRITE setPen
               NOTIFY colorChanged)
    Q_PROPERTY(QBrush brush
               READ brush WRITE setBrush
               NOTIFY colorChanged)
public:
    explicit Figure(QPointF point, QObject *parent = 0);

    QPointF startPoint() const; // Стартовая точка
    QPointF endPoint() const;   // Конечная точка
    QPen  pen() const;
    QBrush  brush() const;
    QPointF center() const;

    void setStartPoint(const QPointF point);
    void setEndPoint(const QPointF point);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);
    void setSelected();
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value);
   // virtual void highlight();
signals:
    void pointChanged();
    void colorChanged();
    void selectedChanged(bool selected);

protected:
    virtual QRectF boundingRect() const;

private:
    QPointF m_startPoint;
    QPointF m_endPoint;

    QPen m_pen;
    QBrush m_Brush;

public slots:
    void updateRomb();
};


#endif // FIGURE_H
