#include <string>
#include <sstream>
#include <vector>

using namespace std;

#include <BoundingBox.h>
#include <Point.h>
#include <Polygon.h>
#include <County.h>

Polygon::Polygon( string regionName, string boundingName )
{

  this->regionName = regionName;
  this->boundingName = boundingName;

}

Polygon::Polygon()
{

  regionName = "default";
  boundingName = "default";

}

Polygon::~Polygon()
{

  for( unsigned int i = 0; i < vertices.size(); i++ )
  {

    delete vertices[ i ];

  }

  vertices.clear();

}

string Polygon::getSvg( BoundingBox &bb, vector<County*> &counties )
{

  stringstream coords( " " );

  for( unsigned int i = 0; i < vertices.size(); i++ )
  {
    
    bb.translatePoint( *vertices[ i ] );
    coords << vertices[ i ]->getX() << "," << vertices[ i ]->getY() << " ";

  }

  unsigned int location = counties.size()+1;
  for( unsigned int i = 0; i < counties.size(); i++ )
  {

    if( regionName == counties[ i ]->getCountyName() && boundingName == counties[ i ]->getStateName() )
    {
      
      location = i;

    }
  }

  stringstream RGB;
  if( location < counties.size() )
  {

    double rVote = counties[ location ]->getRVote();
    double dVote = counties[ location ]->getDVote();
    double oVote = counties[ location ]->getOVote();
    double denominator = rVote+dVote+oVote;

    int R = ( rVote/denominator )*255;
    int B = ( dVote/denominator )*255;
    int G = ( oVote/denominator )*255;
    RGB << R << "," << G << "," << B;

  }else
  {
    
    RGB << "255,255,255";
  
  }

  string result = "<polygon points=\""+coords.str()+"\" style=\"fill:rgb("+RGB.str()+");stroke:black;stroke-width:1\" />";
  return result;

}

string Polygon::getRegionName()
{

  return regionName;

}

string Polygon::getBoundingName()
{

  return boundingName;

}

void Polygon::addPoint( Point* p )
{

  vertices.push_back( p );

}

void Polygon::setRegionName( string name )
{

  regionName = name;

}

void Polygon::setBoundingName( string name )
{

  boundingName = name;

}
