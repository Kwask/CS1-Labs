#ifndef POLYGON_H
#define POLYGON_H

#include <string>
#include <vector>

using namespace std;

#include <BoundingBox.h>
#include <Point.h>
#include <County.h>

class Polygon
{

private:
  vector<Point*> vertices;
  string regionName;
  string boundingName;

public:
  Polygon( string regionName, string boundingName );
  Polygon();
  virtual ~Polygon();

  string getSvg( BoundingBox &bb, vector<County*> &counties );
  string getRegionName();
  string getBoundingName();

  void addPoint( Point* p );
  void setRegionName( string name );
  void setBoundingName( string name );

};

#endif
