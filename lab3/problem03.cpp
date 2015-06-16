#include <iostream>

using namespace std;

bool valid( int value, int min = 0,  int max = 1 )
{

  if( value > max || value < min )
  {

    return false;

  }else
  {

    return true;

  }
}

int main()
{

  int input[ 3 ] = { 0, 0, 0, };
  char throwaway;

  cout << "Enter a date in the following formrat m/d/y: " << endl;
  cin >> input[ 0 ] >> throwaway >> input[ 1 ] >> throwaway >> input[ 2 ];

  if( valid( input[ 0 ], 1, 12 ) == false || valid( input[ 1 ], 1, 31 ) == false || valid( input[ 2 ], 1, 99 ) == false )
  {

    cout << "Not a valid input!" << endl;
  
  }

  if( input[ 0 ]*input[ 1 ] == input[ 2 ] )
  {

    cout << "The date " << input[ 0 ] << "/" << input[ 1 ] << "/" << input[ 2 ] << " is a magic date." << endl;

  }else
  {
    cout << "The date " << input[ 0 ] << "/" << input[ 1 ] << "/" << input[ 2 ] << " is NOT a magic date." << endl;

  }

}
