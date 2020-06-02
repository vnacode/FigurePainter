#ifndef PAINTSCENE_H
#define PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "figure.h"

class PaintScene : public QGraphicsScene
{
    Q_OBJECT
    // Свойство текущего типа используемой фигуры
    Q_PROPERTY(int typeFigure
               READ typeFigure WRITE setTypeFigure
               NOTIFY typeFigureChanged)
    Q_PROPERTY(int currentAction
               READ currentAction WRITE setCurrentAction
               NOTIFY currentActionChanged)


public:
    explicit PaintScene(QObject *parent = 0);

    inline int typeFigure() const {return  m_typeFigure;}                  // Возвращение текщего типа
    inline void setTypeFigure(const int type) { m_typeFigure = type; m_currentAction = NO_ACTION; }     // Установка текущего типа
    inline int currentAction() const {return  m_currentAction;}
    inline void setCurrentAction(const int action) {m_currentAction = action;}
    // Перечисление типов используемых фигур

    enum Actions{
        NO_ACTION,
        Paint,
        Move
    };

    enum FigureTypes {
        NONE,
        SquareType,
        RombType,
        TriangleType,
        EllipseType,
        LineType
    };

signals:
    void typeFigureChanged();
    void currentActionChanged();

private:

    Figure *tempFigure;
    int m_typeFigure;
    int m_currentAction;

private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void drawFigure(QGraphicsSceneMouseEvent *event);
};

#endif // PAINTSCENE_H
