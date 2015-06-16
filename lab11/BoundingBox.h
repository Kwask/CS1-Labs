#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <string>

using namespace std;

#include <Point.h>

class BoundingBox
{

private:
  double minLong;
  double minLat;
  double maxLong;
  double maxLat;
  double difLong;
  double difLat;
  double width;
  double height;
  double translateLatitude( double latitude );
  double translateLongitude( double longitude );

public:
  BoundingBox( double minLong, double minLat, double maxLong, double maxLat );
  virtual ~BoundingBox();

  void translatePoint( Point &point );
  void setMinLong( double minLong );
  void setMinLat( double minLat );
  void setMaxLong( double maxLong );
  void setMaxLat( double maxLat );

  double getMinLong();
  double getMinLat();
  double getMaxLong();
  double getMaxLat();
  double getWidth();
  double getHeight();

  string getSvg();

};

#endif
