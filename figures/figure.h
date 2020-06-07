#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QPen>
#include <QBrush>
#include <QModelIndex>

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

    QPointF startPoint() const;
    QPointF endPoint() const;
    QPen  pen();
    QBrush  brush() const;
    QPointF center() const;

    void setStartPoint(const QPointF point);
    void setEndPoint(const QPointF point);
    void setPen(const QPen &pen);
    void setBrush(const QBrush &brush);

    inline int getId() const { return id; }
    inline void setId(int newid) { id = newid; }

    inline QString getFigureName() const { return figureName; }
    inline void setFigureName(const QString &name) { figureName = name; }

signals:
    void pointChanged();
    void colorChanged();
    void selectedChanged(bool selected);

protected:
    virtual QRectF boundingRect() const;
    virtual void setSelectionHighlight(bool selected);
    inline QPen getDefaultPen() const { return  QPen(QColor(0,0,230),2); }
private:
    int id;
    QString figureName;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    QPointF m_startPoint;
    QPointF m_endPoint;
    QPen m_pen;
    QBrush m_Brush;

public slots:
    void updateRomb();
};


#endif // FIGURE_H
