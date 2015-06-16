#include <iostream>

using namespace std;

int main()
{

  int input[ 3 ] = { 0, 0, 0 };
  int maximum = 0;
  int minimum = 0;

  bool finished = false;

  cout << "Enter three numbers: " << endl;
  cin >> input[ 0 ] >> input[ 1 ] >> input[ 2 ];

  while( finished == false )
  {
  
    for( int i = 0; i == 2; i++ )
    {

      if( i != 2 && input[ i ] > input[ i+1 ] )
      {

        int temp = input[ i+1 ];
        input[ i+1 ] = input[ i ];
        input[ i ] = temp;

        finished = false;

      }else if( i == 2 && input[ i ] < input[ i-1 ] )
      {
        
        int temp = input[ i-1 ];
        input[ i-1 ] = input[ i ];
        input[ i ] = temp;

        finished = false;

      }else
      {

        finished = true;
      
      }
    }
  }

  minimum = input[ 0 ];
  maximum = input[ 2 ];

  cout << "Minimum of " << input[ 0 ] << ", " << input[ 1 ] << ", and " << input[ 2 ] << " is " << minimum << endl;
  cout << "Maximum of " << input[ 0 ] << ", " << input[ 1 ] << ", and " << input[ 2 ] << " is " << maximum << endl;

  return 0;

}
