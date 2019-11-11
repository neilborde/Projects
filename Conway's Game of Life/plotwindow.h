#ifndef PLOTWINDOW_H
#define PLOTWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "cell.h"
#include <vector>
#include <cmath>

namespace Ui {
class PlotWindow;
}

class PlotWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlotWindow(QWidget *parent = 0);
    ~PlotWindow();
    int AliveCells(Cell *c);
    void StepForward();
    int Population();
    int Percentage(){
        return floor(Population()/2);
    }

private slots:
    // default signal -> default slot

    // default signal -> custom slot
    // 1. implement SlotTest
    // 2. connect to a signal
    //void SlotTest();

    //void AddCell();

    //void CellClickedSlot(Cell *p);

    //void SecondClicked(Cell *p);

    //void on_deleteCells_clicked();

    void on_StepForward_clicked();

    void update();

    void on_Play_clicked();

    void on_Pause_clicked();

    void on_Green_clicked();

    void on_Blue_clicked();

    void on_Pink_clicked();

    void on_Black_clicked();

    void on_Red_clicked();

    void on_Set_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_sliderReleased();


private:
    Ui::PlotWindow *ui;

    QGraphicsScene *scene;
    QGraphicsScene *scene2;
    static int random_clicks_;

    Cell * first;

    bool delete_mode;

    std::vector<std::vector<Cell*>> grid_;
    int speed_ = 1000;
    QTimer * timer_;
    int turn_count;
    QColor alive_;
    QColor dead_;
    int overpop_;
    int underpop_;
    std::vector<double> percentages_;
    double height_;
    double width_;
};


#endif // PLOTWINDOW_H
