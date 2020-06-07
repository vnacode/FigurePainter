#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,800);
    this->setWindowTitle("Figure Painter");

    scene = new PaintScene(this);

    m_model = new model();
    ui->listView->setModel(m_model);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);
    ui->graphicsView->setOptimizationFlags(QGraphicsView::DontSavePainterState);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    ui->graphicsView->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    ui->listView->setSelectionMode(QAbstractItemView::ExtendedSelection);

    /// need to correct glitch while paint figure

    connect(scene, &PaintScene::selectionChanged, [=]()
    {
        for (auto *si : scene->items())
        {
            ui->listView->selectionModel()->select(m_model->getItemIndex(si), si->isSelected() ?
                                                       QItemSelectionModel::Select : QItemSelectionModel::Deselect);
        }
        ui->deleteButton->setEnabled(scene->selectedItems().length() > 0 ? true : false);
    });

    connect(ui->listView->selectionModel(), &QItemSelectionModel::selectionChanged, m_model, &model::changeSelection);
    connect(scene, &PaintScene::newFigureAdded, m_model, &model::addFigure);
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


void MainWindow::on_rombButton_clicked()
{
    scene->setTypeFigure(PaintScene::RombType);
}

void MainWindow::on_squareButton_clicked()
{
    scene->setTypeFigure(PaintScene::SquareType);
}

void MainWindow::on_triangleButton_clicked()
{
    scene->setTypeFigure(PaintScene::TriangleType);
}

void MainWindow::on_ellipseButton_clicked()
{
    scene->setTypeFigure(PaintScene::EllipseType);
}

void MainWindow::on_lineButton_clicked()
{
    scene->setTypeFigure(PaintScene::LineType);
}

void MainWindow::on_cursorButton_clicked()
{
    scene->setTypeFigure(PaintScene::NONE);
    scene->setCurrentAction(PaintScene::NO_ACTION);
}

void MainWindow::on_clearButton_clicked()
{
    scene->setTypeFigure(PaintScene::NONE);
    scene->setCurrentAction(PaintScene::NO_ACTION);
    m_model->clearAll();
    //  scene->clear();
}

void MainWindow::on_deleteButton_clicked()
{
    m_model->clearSelected();
}
