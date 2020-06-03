#include "paintscene.h"
#include "romb.h"
#include "triangle.h"
#include "square.h"
#include "ellipse.h"
#include <line.h>

PaintScene::PaintScene(QObject *parent)
    : QGraphicsScene(parent),
      m_typeFigure(NONE),
      m_currentAction(NO_ACTION)
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

    this->update(QRectF(0,0,this->width(), this->height()));
}

void PaintScene::drawFigure(QGraphicsSceneMouseEvent *event)
{
    switch (m_typeFigure) {
    case NONE: {
        return;
    }

    case SquareType: {
        tempFigure = new Square(event->scenePos());
        break;
    }
    case RombType: {
        tempFigure = new Romb(event->scenePos());
        break;
    }
    case TriangleType: {
       tempFigure = new Triangle(event->scenePos());
        break;
    }
    case EllipseType: {
        tempFigure = new Ellipse(event->scenePos());
        break;
    }
    case LineType: {
        tempFigure = new Line(event->scenePos());
        break;
    }
    };

    tempFigure->setPos(event->pos());
    setCurrentAction(Paint);
    this->addItem(tempFigure);
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
