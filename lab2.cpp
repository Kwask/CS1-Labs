//***************************************************************
//
// Title: Winchill calculation
// Author: Charles Hirzel
// CS1021-001 Date: January 20, 2014
// Laboratory: 2
//
//***************************************************************
//
// Description: This program gets two inputs from the user, one for
//  temperature and one for wind speed. The program then calculates
//  and displays wind chill in both the new and old equations in
//  both fahrenheit and centigrade.
//
// Input: Only from user.
//
// Output: Displays to the terminal the calculate wind chill from
//  the old and new equations and in fahrenheit and centigrade.
//
// Procedure: The program will ask the user for the temperature,
//  then asks for the wind speed. The display then displays the
//  calculated wind chill.
//
// Constraints: Must display exactly as it does in the lab packet.
//
// ***********Begin Program**************************************

#include <iostream>
#include <cmath>

using namespace std;

// Function for calculating the wind chill
int *windchill( int temp, int windSpeed )
{

  static int output[ 2 ];

  // Old wind chill formula
  output[ 0 ] = round( 0.0817*(( 3.71*pow( windSpeed, 0.5 ))+5.81-( 0.25*windSpeed ))*( temp-91.4 )+91.4 );
  // New wind chill formula
  output[ 1 ] = round( 35.74+( 0.6215*temp )-(35.75*pow( windSpeed, 0.16 ))+( 0.4275*temp*pow( windSpeed, 0.16 )));

  return output;

}

// Funciton for converting from fahrenheit to centigrade
int FToC( int temp )
{

  int output = round( ( temp-32 )*0.5555555 );

  return output;

}

// Main function
int main()
{

  // Variables required for the program
  int temp = 0;
  int wind = 0;
  int *output;

  // Asks the user for the input for the program
  cout << "Please enter a temperature in degrees Fahrenheit: " << endl;
  cin >> temp;
  cout << "Please enter the wind speed in MPH: " << endl;
  cin >> wind;

  // Calculates the wind chill
  output = windchill( temp, wind );

  // Outputs the results
  cout << "Temperature: " << temp << "  degrees Fahrenheit" << endl
       << "  new wind chill formula: " << output[ 1 ] << endl
       << "  old wind chill formula: " << output[ 0 ] << endl
       << "Temperature: " << FToC( temp ) << " Centigrade" << endl
       << "  new wind chill formula: " << FToC( output[ 1 ] ) << endl
       << "  old wind chill formula: " << FToC( output[ 0 ] ) << endl;

}
