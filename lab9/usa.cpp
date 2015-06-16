//***************************************************************
//
// Title: USA
// Author: Charles Hirzel
// CS1021-001 Date: March 27, 2014
// Laboratory: 9
//
//***************************************************************
//
// Description: This program displays the USA using SVG 
// Input: The file USA.txt
// Output: The file usa.html
// Procedure: Run the program with the USA.txt file in the same folder
// Constraints: Must read from the USA.txt file and output the usa.html
//   file.
//
// ***********Begin Program**************************************
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdlib>

using namespace std;

// Combines a given string and an in input
string combineSandI( string output, int input )
{

  stringstream temp;
  temp << input;
  output += temp.str();

  return output;

}

// Convert from longitude to x-coords
string convertX( float x, float minX, float maxX, int width )
{

  stringstream temp;

  float difference = abs( maxX-minX );
  float displace = abs( x-minX );

  temp << ceil( width*( displace/difference ));

  return temp.str();

}

// Convert from latitude to y-coords
string convertY( float y, float minY, float maxY, int height )
{

  stringstream temp;

  float difference = abs( maxY-minY );
  float displace = abs( difference-( y-minY ));

  temp << ceil( height*( displace/difference ));

  return temp.str();

}

// Draws a polygon from a given string of coords
string drawPoly( string coords, string color )
{

  string result = "<polygon points=\"" + coords + "\" style=\"fill:white;stroke:" + color + ";stroke-width:1\" />";
   
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

  // Difference between min and max longitudes and latitudes
  float longDif = ceil( abs( maxLong-minLong ));
  float latDif = ceil( abs( minLat-maxLat ));
  float ratio = longDif/latDif;

  // Length and width of the image
  int svgWidth = 1000;
  int svgHeight = svgWidth/ratio;

  cout << "Min Long: " << minLong << " Lat: " << minLat << endl
       << "Max Long: " << maxLong << " Lat: " <<  maxLat << endl
       << "Regions: " << subRegions << endl;
  
  // String for bounding box coords
  stringstream temp;
  temp << 0 << "," << 0
       << " " << 0 << "," << svgHeight
       << " " << svgWidth << "," << svgHeight 
       << " " << svgWidth << "," << 0 << " ";
  string boundBox = temp.str();

  ofstream output;
  output.open( "usa.html" );
  
  // Setting the image height and width and drawing bounding box
  output << "<html><body>" << endl
         << "  <svg height=\"" << svgHeight << "\" width=\"" << svgWidth << "\">" << endl;
  output << "    " << drawPoly( boundBox, "red" ) << endl;
    
  for( int i = 0; i < subRegions; i++ )
  {
    
    string trash;
    string region = " ";
    
    int vertices;
    
    // Dumping the crap lines
    input.ignore();
    getline( input, trash );
    getline( input, trash );
    getline( input, trash );
    
    input >> vertices;

    for( int j = 0; j < vertices; j++ )
    {
    
      float tempLong = 0;
      float tempLat = 0;
      
      // Reading in vertex points and converts to svg units
      input >> tempLong >> tempLat;
      string x = convertX( tempLong, minLong, maxLong, svgWidth );
      string y = convertY( tempLat, minLat, maxLat, svgHeight );
      
      region += x + "," + y + " ";
    
    }
     
    output << "    " << drawPoly( region, "black" ) << endl;;

  }

  output << "  </svg>" << endl
         << "</body></html>";
  output.close();
  input.close();

  return 0;

}
