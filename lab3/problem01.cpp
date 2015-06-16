#include <iostream>

using namespace std;

int main()
{

  int input[ 2 ] = { 0, 0 };
  int maximum = 0;
  int minimum = 0;

  cout << "Enter two numbers: " << endl;
  cin >> input[ 0 ] >> input[ 1 ];

  if( input[ 0 ] > input[ 1 ] )
  {
    
    maximum = input[ 0 ];
    minimum = input[ 1 ];  
  

  }else if( input[ 0 ] < input[ 1 ] )
  {
    
    maximum = input[ 1 ];
    minimum = input[ 0 ];

  }else
  {

    cout << "Must be different values!" << endl;
    return -1;

  }

  cout << "Minimum of " << input[ 0 ] << " and " << input[ 1 ] << " is " << minimum << endl;
  cout << "Maximum of " << input[ 0 ] << " and " << input[ 1 ] << " is " << maximum << endl;

  return 0;

}
