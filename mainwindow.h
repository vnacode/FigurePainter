#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QResizeEvent>

#include "paintscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PaintScene *scene;  // Объявляем кастомную графическую сцену
    QTimer *timer;      /* Определяем таймер для подготовки актуальных размеров
                         * графической сцены
                         * */
private:
    /* Переопределяем событие изменения размера окна
     * для пересчёта размеров графической сцены
     * */
    void resizeEvent(QResizeEvent * event);

    QMap<int,QPixmap*> m_figuresIcons;
    void changeCurrentIcon(const int icon);

private slots:
    // Таймер для изменения размеров сцены при изменении размеров Окна приложения
    void slotTimer();
    void on_pushButton_clicked();       // Включаем отрисовку Ромба
    void on_pushButton_2_clicked();     // Включаем отрисовку Квадрата
    void on_pushButton_3_clicked();     // Включаем отрисовку Треугольника
    void on_pushButton_4_clicked();
    void on_pushButton_6_clicked();;
};

#endif // MAINWINDOW_H
