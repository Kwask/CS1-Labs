#include <cmath>
#include <sstream>
#include <string>

using namespace std;

#include <BoundingBox.h>
#include <Point.h>

BoundingBox::BoundingBox( double minLong, double minLat, double maxLong, double maxLat )
{
    
  this->minLong = minLong;
  this->minLat = minLat;
  this->maxLong = maxLong;
  this->maxLat = maxLat;

  // Finding the difference in longitude and latitude
  difLong = abs( maxLong-minLong );
  difLat = abs( maxLat-minLat );

  double ratio = difLong/difLat;

  if( difLong > difLat )
  {

    width = 1000;
    height = width/ratio;

  }else
  {
    
    height = 1000;
    width = height*ratio;

  }
  
}

BoundingBox::~BoundingBox()
{

  return;

}

double BoundingBox::translateLongitude( double longitude )
{

  float displacement = abs( longitude-minLong );

  int x = width*( displacement/difLong );

  return x;

}

double BoundingBox::translateLatitude( double latitude )
{

  float displacement = abs( difLat-( latitude-minLat ));

  int y = height*( displacement/difLat );

  return y;

}

void BoundingBox::translatePoint( Point &point )
{

  point.setX( translateLongitude( point.getX() ));
  point.setY( translateLatitude( point.getY() ));

}

void BoundingBox::setMinLong( double minLong )
{

  this->minLong = minLong;

}

void BoundingBox::setMinLat( double minLat )
{

  this->minLat = minLat;

}

void BoundingBox::setMaxLong( double maxLong )
{

  this->maxLong = maxLong;

}

void BoundingBox::setMaxLat( double maxLat )
{

  this->maxLat = maxLat;

}

double BoundingBox::getMinLong()
{

  return minLong;

}

double BoundingBox::getMinLat()
{

  return minLat;

}

double BoundingBox::getMaxLong()
{

  return maxLong;

}

double BoundingBox::getMaxLat()
{

  return maxLat;

}

double BoundingBox::getWidth()
{

  return width;

}

double BoundingBox::getHeight()
{

  return height;

}

string BoundingBox::getSvg()
{
  
  stringstream result;
  result << "<svg height=\"" << height << "\" width=\"" << width << "\">";

  return result.str();

}
