#include "paintscene.h"
#include "romb.h"
#include "triangle.h"
#include "square.h"
#include "ellipse.h"
#include <line.h>

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{

}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

    if (m_currentAction == Paint)
    {
        tempFigure->setEndPoint(event->scenePos());
    }
    if (tempFigure != Q_NULLPTR &&  m_currentAction == Move && event->buttons() == Qt::LeftButton)
    {
        tempFigure->setPos(tempFigure->scenePos() - (event->lastScenePos() - event->scenePos()));
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
        Square *item = new Square(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        m_currentAction = Paint;
        break;
    }
    case RombType: {
        Romb *item = new Romb(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        m_currentAction = Paint;
        break;
    }
    case TriangleType: {
        Triangle *item = new Triangle(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        m_currentAction = Paint;
        break;
    }
    case EllipseType: {
        Ellipse *item = new Ellipse(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        m_currentAction = Paint;
        break;
    }
    case LineType: {
        Line *item = new Line(event->scenePos());
        item->setPos(event->pos());
        tempFigure = item;
        m_currentAction = Paint;
        break;
    }
    };

    this->addItem(tempFigure);
}


void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_currentAction == Paint)
    {
        m_currentAction = NO_ACTION;
        return;
    }
    if (m_currentAction == Move)
    {
        tempFigure =  static_cast<Figure*>(itemAt(event->scenePos(),QTransform()));
        return;
    }

    drawFigure(event);
}
