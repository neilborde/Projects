#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>

#include "cell.h"
#include "plotwindow.h"

/**
  Creates a new Cell object with coordinates x and y
  @param x int x coordinate
  @param y int y coordinate

*/

/*Constructor, takes color, x and y position, dead or alive bool, row and colulmn*/
Cell::Cell(QColor color, const int x, const int y, bool dead, int r, int c) {
  this->color_ = color;
  x_ = x;
  y_ = y;
  is_dead_ = dead;
  row_ = r;
  column_ = c;
}

//need for paint
QRectF Cell::boundingRect() const
{
    return QRectF(x_, y_, width_, width_);
}


//need for paint
QPainterPath Cell::shape() const
{
    QPainterPath path;
    path.addRect(x_, y_, width_, width_);
    return path;
}


//creates visual representation of object
void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);


    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_));
    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->width_));
    painter->setBrush(b);
}


//in Cell.cpp
//Overriding mouse click events, takes event as argument
void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //if right click
    if(event->button() == Qt::RightButton){
        if(is_dead_ == false){
            next_dead_ = true;
            QColor c_dead(193,200,212);
            color_ = c_dead;
            update();
            qDebug() << is_dead_;
        }
    }
    else{
        if(is_dead_ == true){
            next_dead_ = false;
            QColor c(0,0,155);
            color_ = c;
            update();
            qDebug() << is_dead_;        }
    }

}

/**
  Calculates the distance between this Cell and another Cell.
  @param other Cell object to calculate the distance to
*/
//double Cell::Distance(const Cell &other) const {
//  double distance = (x_ - other.get_x()) * (x_ - other.get_x());
//  distance += (y_ - other.y_) * (y_ - other.y_);
//  return sqrt(distance);
//}


/**
  Makes it so the == operator will have the behavior that you
  expect when comparing Cells.
  You can overload pretty much any operator in c++
  @param first Cell left hand side of the expression
  @param other Cell right hand side of the expression
*/
//override operator
bool operator==(const Cell &first, const Cell &other) {
  return first.x_ == other.x_ && first.y_ == other.y_;
}
