//***************************************************************
//
// Title: USA
// Author: Charles Hirzel
// CS1021-001 Date: April 7, 2014
// Laboratory: 11-12
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
#include <vector>
#include <set>

using namespace std;

#include <BoundingBox.h>
#include <Point.h>
#include <Polygon.h>
#include <County.h>

int main()
{

  int totalRegions = 0;

  double minLong = 0;
  double minLat = 0;
  double maxLong = 0;
  double maxLat = 0;

  vector<Polygon*> regions;

  set<string> states;

  ifstream input;
  input.open( "USA-county.txt" );

  ofstream output;
  output.open( "usa.html" );

  input >> minLong >> minLat >> maxLong >> maxLat >> totalRegions;
  BoundingBox boundingBox( minLong, minLat, maxLong, maxLat );

  // Setting the image height and width and drawing bounding box
  output << "<html><body>" << endl
         << "  " << boundingBox.getSvg() << endl;

  // Load data from file
  for( int region = 0; region < totalRegions; region++ )
  {

    regions.push_back( new Polygon() );

    // Getting the subregion name
    string line = "";
    while( line == "" )
    {
      getline( input, line );
    }

    if( line != "USA" && line != "" )
    {

      regions[ region ]->setRegionName( line );

      getline( input, line );

      regions[ region ]->setBoundingName( line );

    }

    // Getting the vertex count for the subregion
    int count;
    input >> count;

    // Loading in the subregion vertices
    for( int i = 0; i<=count; i++ )
    {

      string line = "";

      getline( input, line );

      if( line != "" )
      {

        regions[ region ]->addPoint( new Point( line ));
      
      }
    }
  }

  input.close();

  // Insert state names into a set
  for( unsigned int i = 0; i < regions.size(); i++ )
  {

    states.insert( regions[ i ]->getBoundingName() );

  }

  // Loads in the county voting data
  vector<County*> counties;
  for( set<string>::iterator it = states.begin(); it != states.end(); it++ )
  {

    string fileName = ( *it ) + "2012.txt";
    string line = "";

    ifstream countyFile;
    countyFile.open( fileName.c_str() );

    getline( countyFile, line );

    while( !countyFile.eof() )
    {

      getline( countyFile, line );

      if( line != "" )
      {
        
        counties.push_back( new County( line, *it ));
      
      }
    }

    countyFile.close();

  }

  // Output the polygons
  for( unsigned int i = 0; i < regions.size(); i++ )
  {

    output << "    " << regions[ i ]->getSvg( boundingBox, counties ) << endl;

  }

  output << "  </svg>" << endl
         << "</body></html>";

  for( unsigned int i = 0; i < counties.size(); i++ )
  {

    delete counties[ i ];

  }

  for( unsigned int i = 0; i < regions.size(); i++ )
  {

    delete regions[ i ];

  }

  counties.clear();
  regions.clear();

  output.close();

  return 0;

}
