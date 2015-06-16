#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string combineSandI( string output, int input )
{

  stringstream temp;
  temp << input;
  output += temp.str();

  return output;

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
  float subRegions = 0;

  ifstream input;
  input.open( "USA.txt" );

  input >> minLong >> minLat >> maxLong >> maxLat >> subRegions;

  input.close();

  cout << "Min Long" minLong << " " << minLat << endl
       << maxLong << endl
       << "Max Long: " maxLat << endl
       << subRegions << endl;

  int svgHeight = 1000;
  int svgWidth = 1000;

  ofstream output;
  output.open( "svg.html" );
  output << "<svg height=\"" << svgHeight << "\" width=\"" << svgWidth << "\">" << endl;

  for( int svgPos = 0; svgPos <= svgHeight; svgPos+=100 )
  {
    
    // Lines across x-axis
    output << drawLine( 0, svgPos, 1000, svgPos ) << endl;
    
    //Lines across y-axis
    output << drawLine( svgPos, 0, svgPos, 1000 ) << endl;

  }

  for( int svgX = 0; svgX <= svgWidth; svgX+=100 )
  {

    for( int svgY = 0; svgY <= svgHeight; svgY+=100 )
    {
      
      stringstream temp;
      temp << svgX << " " << svgY;

      output << drawText( svgX, svgY, temp.str() );
      temp.str( "" );

    }
  }

  output << "</svg>";
  output.close();

}
