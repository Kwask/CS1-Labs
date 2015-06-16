//***************************************************************
//
// Title: Sorting
// Author: Charles Hirzel
// CS1021-001 Date: February 24, 2014
// Laboratory: 7
//
//***************************************************************
//
// Description: This program reads in a list of products from a
//  file and sort the data by whatever method the user inputs.
//
// Input: There must be a file named "products.txt" in the same
//  folder as the program. When the program runs, the user must
//  follow the onscreen instructions.
// 
// Output: The sorted lists of the product, depending on what the
//  user chooses, it could be sorted by rating or cost.
// 
// Procedure: Run the program and follow the onscreen instructions.
//
// Constraints: Must use the two types of sorting algorithms.
//
// ***********Begin Program**************************************


#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

struct Product
{

  string name;

  float price;
  float score;

};

// Checked if a list is sorted
bool isSorted( Product list[], int size, int order )
{

  // Ascending is 0
  // Descending is 1

  for( int i = 0; i < size-1; i++ )
  {

    if( order == 0 && list[ i ].score > list[ i+1 ].score )
    {

      return false;

    }else if( order == 1 && list[ i ].score < list[ i+1 ].score )
    {

      return false;

    }
  }

  return true;

}

// Displays the list of products in the correct format
void display( Product list[], int size )
{

  for( int i = 0; i < size; i++ )
  {

    cout << "$ " << setprecision( 2 ) << fixed << list[ i ].price << "  " << list[ i ].score << " stars: " << list[ i ].name << endl;
  
  }
}

// Swaps two values
void swap( int &a, int &b )
{

  int temp = a;
  a = b;
  b = temp;

}

// Sorts products in ascending price via the selection sort algorithm
void selectionSort( Product list[], int size )
{

  for( int fill = 0; fill < size; fill++ )
  {

    int posMin = fill;

    for( int next = fill; next < size; next++ )
    {

      if( list[ next ].price < list[ posMin ].price )
      {

        posMin = next;

      }
    }

    swap( list[ fill ], list[ posMin ] );

    if( isSorted( list, size, 0 ) )
    {
      break;
    }
  }
}

// Sorts products in descending rating via the bubble sort algorithm
void bubbleSort( Product list[], int size )
{

  while( !isSorted( list, size, 1 ))
  {

    for( int i = 0; i < size-1; i++ )
    {

      if( list[ i ].score < list[ i+1 ].score )
      {

        swap( list[ i ], list[ i+1 ] );

      }
    }
  }
}

int main()
{

  ifstream input;
  input.open( "products.txt" );

  string choice;
  string sSize; // String of size

  getline( input, sSize );
  const int size = atoi( sSize.c_str() );
  Product list[ size ];

  // Loading in data
  for( int i = 0; i < size; i++ )
  {

    string temp;

    getline( input, list[ i ].name );

    getline( input, temp );
    list[ i ].price = atof( temp.c_str() );

    getline( input, temp );
    list[ i ].score = atof( temp.c_str() );

  }

  input.close();

  cout << "Popular Tablets: " << endl;
  display( list, size );
  
  // Main program loop
  while( true )
  {
   
    cout << "Sort by price ('p'), review ('r'), or quit ('q')? ";
    cin >> choice;

    if( choice == "q" )
    {

      break;

    }else if( choice == "p" )
    {
    
      selectionSort( list, size );
      cout << endl
           << "Sorted by price: " << endl;
    
    }else if( choice == "r" )
    {
  
      bubbleSort( list, size );
      cout << endl
           << "Sorted by review: " << endl;

    
    }else
    {

      cout << endl
           << "Invalid input!" << endl;
    
    }

    display( list, size );

  }
}
