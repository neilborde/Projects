#include <iostream>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QTimer>

#include "plotwindow.h"
#include "ui_plotwindow.h"
#include "cell.h"

// Names:
//
//

int PlotWindow::random_clicks_ = 0;

//Constructor, takes QWidget
PlotWindow::PlotWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlotWindow)
{
    // we need to set up the ui before we draw on our scene
    ui->setupUi(this);

    // scene is a Celler field of plot window
    scene = new QGraphicsScene;

    // QGraphicsView is a container for a QGraphicsScene
    //set up views and scenes
    QGraphicsView * view = ui->plotGraphicsView;
    view->setScene(scene);
    view->setSceneRect(0,0,view->frameSize().width(),view->frameSize().height());
    scene2 = new QGraphicsScene;
    QGraphicsView * view2 = ui->graphView;
    view2->setScene(scene2);
    view2->setSceneRect(0,0,view2->frameSize().width(),view2->frameSize().height());

    srand(time(0));
    //set class fields
    delete_mode = false;
    QColor c(0, 0, 155);
    QColor c_dead(193,200,212);
    underpop_ = 1;
    overpop_ = 4;
    alive_ = c;
    dead_ = c_dead;
    //width_ = 0;
    height_ = view2->frameSize().height();
    width_ = view2->frameSize().height();
    int x = 0;
    int y = 0;
    //setting up grid
    turn_count = 0;
    for(int i = 0; i < 10; ++i){
        //each of these vects is one row
        std::vector<Cell*> vect;
        for(int j = 0; j < 20; ++j){
            int rand_num = rand()%2;
            if(rand_num){
                Cell * c2 = new Cell(c, x, y, false, i, j);
                vect.push_back(c2);
            }
            else{
                Cell * c2 = new Cell(c_dead, x, y, true, i, j);
                vect.push_back(c2);
            }
            x+=Cell::get_width();
        }
        x = 0;
        //adding rows to grid
        grid_.push_back(vect);
        y+=Cell::get_width();
    }
    //adding grid items to the scene
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 20; ++j){
            scene->addItem(grid_[i][j]);
        }
    }
    //Updating labels
    std::string p1 = "Turn: " + std::to_string(turn_count);
    QString s(p1.c_str());
    ui->turnLabel->setText(s);
    std::string p2 = "Population: " + std::to_string(Population()) + " (" + std::to_string(Percentage()) + "%)";
    QString s2(p2.c_str());
    ui->popLabel->setText(s2);
    //instantiating timer
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer_ = timer;
}


//destructor
PlotWindow::~PlotWindow()
{
    delete ui;
}

// Day 1, Task 4, number 2



//returns population of alive as int
int PlotWindow::Population(){
    int counter = 0;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 20; ++j){
            if(!grid_[i][j]->get_dead()){
                counter++;
            }
        }
    }
    return counter;
}


//determines how many alive neighbors for cell c. Takes parameter c
int PlotWindow::AliveCells(Cell * c){
    int num_cells = 0;
    int right_col = 30;
    int left_col = 30;
    int up_row = 30;
    int down_row = 30;
    //setting right column, left column, upper row, lower row for the cell.
    //edge cases
    if(c->get_row() == 0){
        if(c->get_col() == 0){
            right_col = 1;
            left_col = 19;
            up_row = 9;
            down_row = 1;
        }
        else if(c->get_col() == 19){
            right_col = 0;
            left_col = 18;
            up_row = 9;
            down_row = 1;
        }
        else{
            right_col = c->get_col()+1;
            left_col = c->get_col()-1;
            up_row = 9;
            down_row = 1;
        }
    }
    else if(c->get_col()==0){
        if(c->get_row()==9){
            right_col = 1;
            left_col = 19;
            up_row = 8;
            down_row = 0;
        }
        else{
            right_col = 1;
            left_col = 19;
            up_row = c->get_row() - 1;
            down_row = c->get_row() + 1;
        }
    }
    else if(c->get_row()==9){
        if(c->get_col() == 19){
            right_col = 0;
            left_col = 18;
            up_row = 8;
            down_row = 0;
        }
        else{
            right_col = c->get_col()+1;
            left_col = c->get_col()-1;
            up_row = 8;
            down_row = 0;
        }
    }
    else if(c->get_col()==19){
        right_col = 0;
        left_col = 18;
        up_row = c->get_row()-1;
        down_row = c->get_row()+1;
    }
    //standard case
    else{
        right_col = c->get_col()+1;
        left_col = c->get_col()-1;
        up_row = c->get_row()-1;
        down_row = c->get_row()+1;
    }
    //checking each neighbor
    if(!grid_[c->get_row()][left_col]->get_dead()){
        num_cells++;
    }
    if(!grid_[down_row][c->get_col()]->get_dead()){
        num_cells++;
    }
    if(!grid_[c->get_row()][right_col]->get_dead()){
        num_cells++;
    }
    if(!grid_[up_row][c->get_col()]->get_dead()){
        num_cells++;
    }
    if(!grid_[up_row][left_col]->get_dead()){
        num_cells++;
    }
    if(!grid_[up_row][right_col]->get_dead()){
        num_cells++;
    }
    if(!grid_[down_row][left_col]->get_dead()){
        num_cells++;
    }
    if(!grid_[down_row][right_col]->get_dead()){
        num_cells++;
    }
    return num_cells;

}
//takes one turn, steps forward
void PlotWindow::StepForward(){
    //settign next turn alive or dead value for each cell
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 20; ++j){
            if(!grid_[i][j]->get_dead()){
                if(AliveCells(grid_[i][j]) <= underpop_ || AliveCells(grid_[i][j]) >= overpop_){
                    grid_[i][j]->SetNext(true);

                }
            }
            else{
                if(AliveCells(grid_[i][j])==3){
                    grid_[i][j]->SetNext(false);
                }
            }
        }
    }
    //updating current alive or dead value for each cell and changing color
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 20; ++j){
            grid_[i][j]->SetDead(grid_[i][j]->get_next());
            if(grid_[i][j]->get_dead()){
                grid_[i][j]->SetColor(dead_);
            }
            else{
                grid_[i][j]->SetColor(alive_);
            }
        }
    }
    //increment turn count
    turn_count++;
    //update labels
    std::string p1 = "Turn: " + std::to_string(turn_count);
    QString s(p1.c_str());
    ui->turnLabel->setText(s);
    std::string p2 = "Population: " + std::to_string(Population()) + " (" + std::to_string(Percentage()) + "%)";
    QString s2(p2.c_str());
    //repaint
    scene->update();
    ui->popLabel->setText(s2);
    //GRAPHING
    double per = double(Percentage())/100;
    //add to percentage alive cells to percentages vector of size 20
    if(percentages_.size()==20){
        percentages_.insert(percentages_.begin(), per);
        percentages_.pop_back();
    }
    else{
        percentages_.insert(percentages_.begin(), per);
    }
    //clear previous graph
    scene2->clear();
    //graph each percentage bar in the percentages vector
    for(int i = 0; i < percentages_.size(); ++i){
        per = percentages_[i];
        double size = per*131;
        double start_height = height_-size;
        scene2->addRect((500-(i*25)),start_height,25,size-1);
    }
}

//when step forward clickedd
void PlotWindow::on_StepForward_clicked()
{
    StepForward();
}

//when play clicked
void PlotWindow::on_Play_clicked()
{

    timer_->start(speed_);
}


//when pause clicked
void PlotWindow::on_Pause_clicked()
{
    timer_->stop();
}


//when green clicked
void PlotWindow::on_Green_clicked()
{
    QColor c(51,227,48);
    alive_ = c;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            if(!grid_[i][j]->get_dead()){
                grid_[i][j]->SetColor(c);
            }
        }
    }
    scene->update();

}


//when blue clicked
void PlotWindow::on_Blue_clicked()
{
    QColor c(0, 0, 155);
    alive_ = c;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            if(!grid_[i][j]->get_dead()){
                grid_[i][j]->SetColor(c);
            }
        }
    }
    scene->update();
}

//when pick clicked
void PlotWindow::on_Pink_clicked()
{
    QColor c(236, 16, 234);
    alive_ = c;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            if(!grid_[i][j]->get_dead()){
                grid_[i][j]->SetColor(c);
            }
        }
    }
    scene->update();
}

//slot for play button, calls stepforward
void PlotWindow::update(){
    StepForward();
}

//when black clicked
void PlotWindow::on_Black_clicked()
{
    QColor c(3, 3, 3);
    alive_ = c;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            if(!grid_[i][j]->get_dead()){
                grid_[i][j]->SetColor(c);
            }
        }
    }
    scene->update();
}

//when red clicked
void PlotWindow::on_Red_clicked()
{
    QColor c(200, 0, 0);
    alive_ = c;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            if(!grid_[i][j]->get_dead()){
                grid_[i][j]->SetColor(c);
            }
        }
    }
    scene->update();
}

//when set button clicked
void PlotWindow::on_Set_clicked()
{
    bool safe = false;
    int under = ui->underPop->text().toInt(&safe);
    if (!safe) {
        return;
    }
    // do the same thing for the y coordinate
    int over = ui->overPop->text().toInt(&safe);
    if (!safe) {
        return;
    }
    underpop_ = under;
    overpop_ = over;
}




//when slider value changed.
void PlotWindow::on_horizontalSlider_valueChanged(int value)
{
    speed_ = value;
    std::string p2 = "Speed: " + std::to_string(3000-value) + " milliseconds";
    QString s2(p2.c_str());
    ui->speedLabel->setText(s2);
}

//when slider released by user
void PlotWindow::on_horizontalSlider_sliderReleased()
{
    timer_->setInterval(3000-ui->horizontalSlider->sliderPosition());
}
