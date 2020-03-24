#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QDebug>

class Figure : public QObject, public QGraphicsItem
{
    Q_OBJECT
    // Свойство стартовой точки, относительно которой отрисовываем фигуру
    Q_PROPERTY(QPointF startPoint
               READ startPoint WRITE setStartPoint
               NOTIFY pointChanged)
    // Свойство конечно точки, до куда отрисовываем фигуру
    Q_PROPERTY(QPointF endPoint
               READ endPoint WRITE setEndPoint
               NOTIFY pointChanged)
    Q_PROPERTY(QColor penColor
               READ penColor WRITE setPenColor
               NOTIFY colorChanged)
    Q_PROPERTY(QColor brushColor
               READ brushColor WRITE setBrushColor
               NOTIFY colorChanged)
public:
    explicit Figure(QPointF point, QObject *parent = 0);
    ~Figure();

    QPointF startPoint() const; // Стартовая точка
    QPointF endPoint() const;   // Конечная точка
    QColor  penColor() const;
    QColor  brushColor() const;
    QPointF center() const;

    void setStartPoint(const QPointF point);    // Установка стартовой точки
    void setEndPoint(const QPointF point);      // Установка конечной точки
    void setPenColor(const QColor &color);
    void setBrushColor(const QColor &color);

signals:
    void pointChanged();    // Сигнал об изменении точки
    void colorChanged();
private:
    QRectF boundingRect() const;
    QPointF m_startPoint;   // Стартовая точка
    QPointF m_endPoint;     // Конечная точка
       // Область, в которой содержится фигура
    QColor m_penColor;
    QColor m_BrushColor;

public slots:
    void updateRomb();     // Слот обновления области, в которой содержится фигура
};


#endif // FIGURE_H
