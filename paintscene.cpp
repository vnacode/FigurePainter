#include "paintscene.h"
#include "romb.h"
#include "triangle.h"
#include "square.h"
#include "ellipse.h"
#include <line.h>

PaintScene::PaintScene(QObject *parent)
    : QGraphicsScene(parent),
      m_typeFigure(NONE),
      m_currentAction(NO_ACTION),
      m_currentId(1)
{

}


void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_currentAction == Paint)
    {
        tempFigure->setEndPoint(event->scenePos());
    }
    else
    {
        QGraphicsScene::mouseMoveEvent(event);
    }

    this->update();
}

void PaintScene::drawFigure(QGraphicsSceneMouseEvent *event)
{
    switch (m_typeFigure) {
    case NONE: {
        return;
    }

    case SquareType: {
        tempFigure = new Square(event->scenePos());
        tempFigure->setFigureName("Square");
        break;
    }
    case RombType: {
        tempFigure = new Romb(event->scenePos());
        tempFigure->setFigureName("Square");
        break;
    }
    case TriangleType: {
        tempFigure = new Triangle(event->scenePos());
        tempFigure->setFigureName("Triangle");
        break;
    }
    case EllipseType: {
        tempFigure = new Ellipse(event->scenePos());
        tempFigure->setFigureName("Ellipse");
        break;
    }
    case LineType: {
        tempFigure = new Line(event->scenePos());
        tempFigure->setFigureName("Line");
        break;
    }
    };

    tempFigure->setPos(event->pos());
    tempFigure->setId(m_currentId);
    setCurrentAction(Paint);
    this->addItem(tempFigure);
    emit newFigureAdded(tempFigure);
    m_currentId++;
}


void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
    if (m_currentAction == Paint)
    {
        m_currentAction = NO_ACTION;
        return;
    }

    drawFigure(event);
}
