#ifndef POINT_H
#define POINT_H

#include <string>

using namespace std;

class Point
{

private:
  double x;
  double y;

public:
  Point( double x, double y );
  Point( string line );

  void setX( double x );
  void setY( double y );

  double getX();
  double getY();

};

#endif
