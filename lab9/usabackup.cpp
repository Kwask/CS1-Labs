#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

string combineSandI( string output, int input )
{

  stringstream temp;
  temp << input;
  output += temp.str();

  return output;

}

string convertToPolyCoord( int x1, int y1, int x2, int y2 )
{

  stringstream temp;

  temp << x1 << "," << y1
       << " " << x1 << "," << y2
       << " " << x2 << "," << y2 
       << " " << x2 << "," << y1 << " ";

  return temp.str();

}

string convertX( float x, float minX, float maxX, int width )
{

  stringstream temp;

  float difference = abs( maxX-minX );
  float displace = abs( x-minX );

  temp << ceil( width*( displace/difference ));

  return temp.str();

}

string convertY( float y, float minY, float maxY, int height )
{

  stringstream temp;

  float difference = abs( maxY-minY );
  float displace = abs( y-minY );

  temp << ceil( height*( displace/difference ));

  return temp.str();

}


string drawLine( int x1, int y1, int x2, int y2 )
{

  string result = "<line x1=\"";
  result = combineSandI( result, x1 );

  result += "\" y1=\"";
  result = combineSandI( result, y1 );

  result += "\" x2=\"";
  result = combineSandI( result, x2 );

  result += "\" y2=\"";
  result = combineSandI( result, y2 );

  result += "\" style=\"stroke:rgb(255,0,0);stroke-width:2\" />";
  
  return result;

}

string drawPoly( string coords )
{

  string result = "<polygon points=\"";
  result += coords;

  result += "\" style=\"fill:white;stroke:red;stroke-width:2\" />";
  
  return result;

}

string drawText( int x, int y, string text )
{

  string result = "<text x=\"";
  result = combineSandI( result, x );

  result += "\" y=\"";
  result = combineSandI( result, y );

  result += "\" fill=\"red\">";
  result += text;
  result += "</text>";
  
  return result;

}

int main()
{

  float minLong = 0;
  float minLat = 0;
  float maxLong = 0;
  float maxLat = 0;
  int subRegions = 0;

  ifstream input;
  input.open( "USA.txt" );

  input >> minLong >> minLat >> maxLong >> maxLat >> subRegions;

  float longDif = ceil( abs( maxLong-minLong ));
  float latDif = ceil( abs( minLat-maxLat ));
  float ratio = longDif/latDif;

  int svgWidth = 1000;
  int svgHeight = svgWidth/ratio;

  cout << "Min Long: " << minLong << " Lat: " << minLat << endl
       << "Max Long: " << maxLong << " Lat: " <<  maxLat << endl
       << "Regions: " << subRegions << endl;

  ofstream output;
  output.open( "usa.html" );
  output << "<svg height=\"" << svgHeight << "\" width=\"" << svgWidth << "\">" << endl;

  output << "  " << drawPoly( convertToPolyCoord( 0, 0, svgWidth, svgHeight )) << endl;
    
  for( int i = 0; i < subRegions; i++ )
  {
    
    string trash;
    int vertices;

    input >> trash >> trash >> vertices;

    for( int j = 0; j < vertices; j++ )
    {
    
      float tempLong = 0;
      float tempLat = 0;

      input >> tempLong >> tempLat;
      int x = convertX( tempLong, minLong, maxLong, svgWidth );
      int y = convertY( tempLat, minLat, maxLat, svgHeight );
    
    }
      

  }

  output << "</svg>";
  output.close();

  input.close();

  return 0;

}
