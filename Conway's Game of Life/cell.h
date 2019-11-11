#ifndef CELL_H
#define CELL_H

#include <QColor>
#include <QGraphicsItem>

class Cell : public QObject, public QGraphicsItem {

    Q_OBJECT

public:
    Cell(QColor color, const int x, const int y, bool dead, int r, int c);  // constructor

    int get_x() const { return x_; }  // inline member function
    int get_y() const { return y_; }  // inline member function
    int get_row() const { return row_; }  // inline member function
    int get_col() const { return column_; }
    bool get_dead() const { return is_dead_; }
    bool get_next() const {return next_dead_; }
    void SetDead(bool dead){
        is_dead_ = dead;
    }
    void SetColor(QColor color){
        color_ = color;
    }
    void SetNext(bool dead){
        next_dead_ = dead;
    }

    double Distance(const Cell &other) const;  // member function

    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

    static int get_width() { return width_; };

// in Cell.h
signals:
    // for distance
    void CellSelected(Cell *p);
    void SecondClicked(Cell *p);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;



private:
  int x_;
  int y_;
  QColor color_;
  bool is_dead_;
  int row_;
  int column_;
  bool next_dead_;

  // all our Cells will be 10 wide and tall (they are circles)
  static const int width_ = 20;

  // if you declare the operator as a friend, then it isn't
  // part of the object
  // friend will let this method access the private fields
  friend bool operator==(const Cell &first, const Cell &other);
  static int point_counter;
};  // class Point



#endif // POINT_H
