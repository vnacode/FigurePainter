#include "paintscene.h"
#include "romb.h"
#include "triangle.h"
#include "square.h"
#include "ellipse.h"

PaintScene::PaintScene(QObject *parent) : QGraphicsScene(parent)
{

}

PaintScene::~PaintScene()
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
        tempFigure->setPos(event->scenePos());
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
    default:{
        return;
    }
    }

    this->addItem(tempFigure);
}


void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (m_currentAction == Paint)
    {
      //  this->m_typeFigure = NONE;
        m_currentAction = NO_ACTION;
        return;
    }
    if (m_currentAction == Move)
    {
      //  this->m_typeFigure = NONE;
        tempFigure =  static_cast<Figure*>(itemAt(event->scenePos(),QTransform()));
        return;
    }

    drawFigure(event);
}
