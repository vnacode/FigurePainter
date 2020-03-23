#include "mainwindow.h"
#include "ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(1200,800);
    scene = new PaintScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_figuresIcons[PaintScene::NONE] = new QPixmap(":/images/cursor.png");
    m_figuresIcons[PaintScene::SquareType] = new QPixmap(":/images/rectangle.png");
    m_figuresIcons[PaintScene::RombType] = new QPixmap(":/images/ellipse.png");
    m_figuresIcons[PaintScene::TriangleType] = new QPixmap(":/images/triangle.png");
    m_figuresIcons[PaintScene::EllipseType] = new QPixmap(":/images/ellipse.png");
    m_figuresIcons[PaintScene::LineType] = new QPixmap(":/images/minus.png");

    ui->currenIcon->setScaledContents(true);
    ui->currenIcon->setFixedSize(50,50);

    timer = new QTimer();       // Инициализируем таймер
    connect(timer, &QTimer::timeout, this, &MainWindow::slotTimer);
    timer->start(100);          // Запускаем таймер
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotTimer()
{
    /* Переопределяем размеры графической сцены в зависимости
     * от размеров окна
     * */
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QMainWindow::resizeEvent(event);
}

void MainWindow::changeCurrentIcon(const int icon)
{
    ui->currenIcon->setPixmap(*m_figuresIcons[icon]);
}

// Ромб
void MainWindow::on_pushButton_clicked()
{
    scene->setTypeFigure(PaintScene::RombType);
    changeCurrentIcon(PaintScene::RombType);
}

// Квадрат
void MainWindow::on_pushButton_2_clicked()
{
    scene->setTypeFigure(PaintScene::SquareType);
    changeCurrentIcon(PaintScene::SquareType);
}

// Треугольник
void MainWindow::on_pushButton_3_clicked()
{
    scene->setTypeFigure(PaintScene::TriangleType);
    changeCurrentIcon(PaintScene::TriangleType);
}

void MainWindow::on_pushButton_4_clicked()
{
    scene->setTypeFigure(PaintScene::EllipseType);
    changeCurrentIcon(PaintScene::EllipseType);
}

void MainWindow::on_pushButton_6_clicked()
{
    scene->setTypeFigure(PaintScene::NONE);
    scene->setCurrentAction(PaintScene::Move);
    changeCurrentIcon(PaintScene::PaintScene::NONE);
}


