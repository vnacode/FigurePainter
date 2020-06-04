#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <model.h>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(800,600);
    this->setWindowTitle("Figure Painter");

    scene = new PaintScene(this);
    model *m_model = new model();
    connect(scene, &PaintScene::newFigureAdded, m_model, &model::addObject);
    ui->listView->setModel(m_model);
    ui->graphicsView->setScene(scene);
     ui->graphicsView->setRenderHint(QPainter::Antialiasing);
     ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
     ui->graphicsView->setOptimizationFlags(QGraphicsView::DontSavePainterState);
     ui->graphicsView->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
     ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);

     /// need to correct glitch while paint figure
     connect(scene, &PaintScene::currentActionChanged, [&](const int state)
     {
         ui->graphicsView->setDragMode(state == PaintScene::Paint ? QGraphicsView::NoDrag : QGraphicsView::RubberBandDrag);
     });


    m_figuresIcons[PaintScene::NONE] = new QPixmap(":/images/cursor.png");
    m_figuresIcons[PaintScene::SquareType] = new QPixmap(":/images/rectangle.png");
    m_figuresIcons[PaintScene::RombType] = new QPixmap(":/images/romb.png");
    m_figuresIcons[PaintScene::TriangleType] = new QPixmap(":/images/triangle.png");
    m_figuresIcons[PaintScene::EllipseType] = new QPixmap(":/images/ellipse.png");
    m_figuresIcons[PaintScene::LineType] = new QPixmap(":/images/minus.png");


     ui->graphicsView->resize(645,580);
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
 scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
  QMainWindow::resizeEvent(event);
}

void MainWindow::changeCurrentIcon(const int icon)
{
  //  ui->currenIcon->setPixmap(*m_figuresIcons[icon]);
}

void MainWindow::on_rombButton_clicked()
{
    scene->setTypeFigure(PaintScene::RombType);
    changeCurrentIcon(PaintScene::RombType);
}

void MainWindow::on_squareButton_clicked()
{
    scene->setTypeFigure(PaintScene::SquareType);
    changeCurrentIcon(PaintScene::SquareType);
}

void MainWindow::on_triangleButton_clicked()
{
    scene->setTypeFigure(PaintScene::TriangleType);
    changeCurrentIcon(PaintScene::TriangleType);
}

void MainWindow::on_ellipseButton_clicked()
{
    scene->setTypeFigure(PaintScene::EllipseType);
    changeCurrentIcon(PaintScene::EllipseType);
}

void MainWindow::on_lineButton_clicked()
{
    scene->setTypeFigure(PaintScene::LineType);
    changeCurrentIcon(PaintScene::LineType);
}

void MainWindow::on_cursorButton_clicked()
{
    scene->setTypeFigure(PaintScene::NONE);
    scene->setCurrentAction(PaintScene::NO_ACTION);
    changeCurrentIcon(PaintScene::PaintScene::NONE);
}

void MainWindow::on_clearButton_clicked()
{
    scene->setTypeFigure(PaintScene::NONE);
    scene->setCurrentAction(PaintScene::NO_ACTION);
    changeCurrentIcon(PaintScene::PaintScene::NONE);
    scene->clear();
}
