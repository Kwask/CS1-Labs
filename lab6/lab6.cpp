//***************************************************************
//
// Title: Data Analysis
// Author: Charles Hirzel
// CS1021-001 Date: February 18 2014
// Laboratory: 6
//
//***************************************************************
//
// Description: This program analyses a list of numbers giving
//  statistics such as the total number of values, the number of
//  even and odd values, the number of prime values, and the
//  number of vampire numbers.
//
// Input: The input.txt must be in the same folder as the program
//  and have a list of numbers with a sentinel value of -1 at the
//  end.
//
// Output: Displays the statistic mentioned above as well as the
//  10 highest values
//
// Procedure: Run the program, and it will output the statistics.
//
// Constraints: input.txt must end with a sentinel value of -1
//
// ***********Begin Program**************************************

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

const int SENTINEL = -1;

// First and second halves of the vampire fangs
struct combinations
{

  int first;
  int second;

};

bool isEven( int value )
{

  // If value is divisble by 2, then it is true
  return !(value%2);

}

bool isOdd( int value )
{

  // If value is even, then it is not odd
  return !isEven( value );

}

// If the value is divisble by any number smaller than it or larger than 1, then it is not prime
bool isPrime( int value )
{

  bool prime;

  for( int i = 2; i < ( value/2 )+1; i++ )
  {

    if( value%i == 0 )
    {

      prime = false;
      break;

    }else
    {

      prime = true;

    }
  }

  return prime;

}

bool isVampire( int value )
{

  if( value >= 9999 || value <= 1000 )
  {

    return false;

  }

  // Turning value into string
  stringstream valueSS;
  valueSS << value;
  string valueS = valueSS.str();

  int size = valueS.size();
  int permutations = size*size-4; // 2 sets of numbers per value, size^2 combos = 16 permutations
  int number[ size ];
  combinations combo[ permutations ]; // Strcuture for tracking the combos,   cout << "String: " << valueS << endl;

  for( int i = 0; i < size; i++ )
  {

    // Grabbing individual digits of value
    number[ i ] = valueS[ i ] - '0';

  }

  // Block code for assigning permutations
  combo[ 0 ].first = number[ 0 ]+number[ 1 ]*10;
  combo[ 0 ].second = number[ 2 ]+number[ 3 ]*10;
  combo[ 1 ].first = number[ 1 ]+number[ 0 ]*10;
  combo[ 1 ].second = number[ 2 ]+number[ 3 ]*10;
  combo[ 2 ].first = number[ 0 ]+number[ 1 ]*10;
  combo[ 2 ].second = number[ 3 ]+number[ 2 ]*10;
  combo[ 3 ].first = number[ 1 ]+number[ 0 ]*10;
  combo[ 3 ].second = number[ 3 ]+number[ 2 ]*10;

  combo[ 4 ].first = number[ 0 ]+number[ 2 ]*10;
  combo[ 4 ].second = number[ 1 ]+number[ 3 ]*10;
  combo[ 5 ].first = number[ 2 ]+number[ 0 ]*10;
  combo[ 5 ].second = number[ 1 ]+number[ 3 ]*10;
  combo[ 6 ].first = number[ 0 ]+number[ 2 ]*10;
  combo[ 6 ].second = number[ 3 ]+number[ 1 ]*10;
  combo[ 7 ].first = number[ 2 ]+number[ 0 ]*10;
  combo[ 7 ].second = number[ 3 ]+number[ 1 ]*10;

  combo[ 8 ].first = number[ 0 ]+number[ 3 ]*10;
  combo[ 8 ].second = number[ 1 ]+number[ 2 ]*10;
  combo[ 9 ].first = number[ 0 ]+number[ 3 ]*10;
  combo[ 9 ].second = number[ 2 ]+number[ 1 ]*10;
  combo[ 10 ].first = number[ 3 ]+number[ 0 ]*10;
  combo[ 10 ].second = number[ 1 ]+number[ 2 ]*10;
  combo[ 11 ].first = number[ 3 ]+number[ 0 ]*10;
  combo[ 11 ].second = number[ 2 ]+number[ 1 ]*10;


  for( int i = 0; i < permutations; i++ )
  {

    if( combo[ i ].first*combo[ i ].second == value )
    {

      return true;

    }
  }

  return false;

}

// Function to swap two values in memory
void swap( int &valueA, int &valueB )
{

  int temp = valueB;
  valueB = valueA;
  valueA = temp;

}

// Function to sort list of 10 largest numbers using bubble sort
void addToLargest( int largest[], int size, int value )
{

  for( int i = 0; i < size; i++ )
  {

    if( largest[ i ] < value )
    {

      swap( value, largest[ i ] );

    }
  }
}

int main()
{

  int value;
  int numberCount = 0;
  int evenCount = 0;
  int oddCount = 0;
  int primeCount = 0;
  int vampireCount = 0;
  int largestValues[ 10 ] = {};

  string filename = "input.txt";

  ofstream writeEven;
  ofstream writeOdd;
  writeEven.open( "evens.txt" );
  writeOdd.open( "odds.txt" );

  ifstream read;
  read.open( filename.c_str() );

  read >> value;

  while( value != SENTINEL && !read.eof() )
  {

    numberCount++;

    addToLargest( largestValues, 10, value );

    if( isEven( value ))
    {

      // Increases even count, and writes the even number to evens.txt
      evenCount++;
      writeEven << value << endl;

    }else if( isOdd( value ))
    {

      // Increases odd count, and writes the odd number to odds.txt
      oddCount++;
      writeOdd << value << endl;

    }

    if( isPrime( value ))
    {

      primeCount++;

    }

    if( isVampire( value ))
    {

      vampireCount++;

    }

    read >> value;

  }

  read.close();
  writeEven.close();
  writeOdd.close();

  cout << "Numbers read in: " << numberCount << endl
       << "Even numbers: " << evenCount << endl
       << "Odd numbers: " << oddCount << endl
       << "Prime numbers: " << primeCount << endl
       << "Vampire numebrs: " << vampireCount << endl
       << "Ten largest numbers: " << endl;

  // Printing ten largest numbers
  for( int i; i < 10; i++ )
  {

    cout << "  -- " << largestValues[ i ] << endl;

  }

  return 0;
}

