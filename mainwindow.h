#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QResizeEvent>

#include "paintscene.h"
#include <model.h>

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
    PaintScene *scene;
    QTimer *timer;

private:

    void resizeEvent(QResizeEvent * event);
    model *m_model;
private slots:

    void on_rombButton_clicked();
    void on_squareButton_clicked();
    void on_triangleButton_clicked();
    void on_ellipseButton_clicked();
    void on_lineButton_clicked();
    void on_cursorButton_clicked();
    void on_clearButton_clicked();
    void on_deleteButton_clicked();
};

#endif // MAINWINDOW_H
