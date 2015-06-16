//***************************************************************
//
// Title: USA
// Author: Charles Hirzel
// CS1021-001 Date: April 2, 2014
// Laboratory: 10
//
//***************************************************************
//
// Description: This program displays the USA using SVG 
// Input: The file USA.txt
// Output: The file usa.html
// Procedure: Run the program with the USA.txt file in the same folder
// Constraints: Must read from the USA.txt file and output the usa.html
//   file. Must be object-oriented
//
// ***********Begin Program**************************************
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <BoundingBox.h>
#include <Point.h>

using namespace std;

// Draws a polygon from a given string of coords
string drawPoly( string coords, string color )
{

  string result = "<polygon points=\"" + coords + "\" style=\"fill:white;stroke:" + color + ";stroke-width:1\" />";
   
  return result;

}

int main()
{

  int subRegions = 0;

  double minLong = 0;
  double minLat = 0;
  double maxLong = 0;
  double maxLat = 0;

  ifstream input;
  input.open( "USA.txt" );

  ofstream output;
  output.open( "usa.html" );

  input >> minLong >> minLat >> maxLong >> maxLat >> subRegions;

  BoundingBox boundingBox( minLong, minLat, maxLong, maxLat );

  // String for bounding box coords
  stringstream boundBox;
  boundBox << 0 << "," << 0
       << " " << 0 << "," << boundingBox.getHeight()
       << " " << boundingBox.getWidth() << "," << boundingBox.getHeight()
       << " " << boundingBox.getWidth() << "," << 0 << " ";

  // Setting the image height and width and drawing bounding box
  output << "<html><body>" << endl
         << "  <svg height=\"" << boundingBox.getHeight() << "\" width=\"" << boundingBox.getWidth() << "\">" << endl
         << "    " << drawPoly( boundBox.str(), "red" ) << endl;
   
  for( int i = 0; i < subRegions; i++ )
  {
    
    string trash;
    stringstream region;
    region.str( " " );
    
    // Dumping the crap lines
    input.ignore();
    getline( input, trash );
    getline( input, trash );
    getline( input, trash );
   
    int vertices; 
    input >> vertices;

    for( int j = 0; j < vertices; j++ )
    {
    
      double tempLong = 0;
      double tempLat = 0;
       
      // Reading in vertex points
      input >> tempLong >> tempLat;
     
      Point* vertex = new Point( tempLong, tempLat );
      boundingBox.translatePoint( *vertex );

      region << vertex->getX() << "," << vertex->getY() << " ";
      
      delete vertex;
    
    }
     
    output << "    " << drawPoly( region.str(), "black" ) << endl;

  }

  output << "  </svg>" << endl
         << "</body></html>";

  output.close();
  input.close();

  return 0;

}
