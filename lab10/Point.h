#ifndef POINT_H
#define POINT_H

using namespace std;

class Point
{

private:
  double x;
  double y;

public:
  Point( double x, double y );

  void setX( double x );
  void setY( double y );

  double getX();
  double getY();

};

#endif
