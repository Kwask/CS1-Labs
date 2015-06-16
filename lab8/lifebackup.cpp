//***************************************************************
//
// Title: Conway's Game of Life
// Author: Charles Hirzel
// CS1021-001 Date: March 10, 2014
// Laboratory: 8
//
//***************************************************************
//
// Description: This program runs a cellular automata simulation
//  using the rules from Conway's Game of Life
//
// Input: Use the command "./a.out < BOARDNAME.txt" to run the
//  program with the desired textfile with the name BOARDNAME.
//  Alternatively, use "./a.out # < BOARDNAME.txt" and replace the
//  "#" with the desired number of generations.
// 
// Output: A visual display of the generations from the given board.
//  
// Procedure: Run the program with the given commands.
//
// Constraints: Must use a textfile for intiail board setup, loop
//  must end with either the generation count or if there was no
//  change in the board.
//
// ***********Begin Program**************************************
//

#include <cstdlib>
#include <iostream>
#include <unistd.h>

using namespace std;

const char DEAD = '.';
const char ALIVE = 'O';

// Converts the x and y compnents into a 1-Dimensional displace component
void convertTo1D( int x, int y, int width, int height, int &displacement )
{

  displacement = y*width+x;

}

// Converts a 1-Dimensional displacement into x and y components
void convertTo2D( int displacement, int width, int height, int &x, int &y )
{

  x = displacement%width;
  y = ( displacement-x )%height;

}

// Copys the data from one board onto another
void copyBoard( char* destination, char* source, int width, int height )
{

  for( int i = 0; i < width*height; i++ )
  {

    char* location = destination+i;
    *location = *( source+i );

  }
}

// Display
void printBoard( char* board, int width, int height )
{

  for( int y = 0; y < height; y++ )
  {

    for( int x = 0; x < width; x++ )
    {

      int displacement = 0;
      convertTo1D( x, y, width, height, displacement );
      cout << *( board+displacement ) << " ";

    }
    
    cout << endl;

  }

  cout << endl;

}

// Counts the number of neighbors with the given check value
int countNeighbors( char* board, int xPos, int yPos, int width, int height, int checkValue )
{

  int count = 0;

  for( int yDisp = -1; yDisp <= 1; yDisp++ )
  {

    for( int xDisp = -1; xDisp <= 1; xDisp++ )
    {

      int x = xPos+xDisp;
      int y = yPos+yDisp;

      if( x >= 0 and x < width and y >= 0 and y < height and ( yDisp != 0 or xDisp != 0 ))
      {

        char* pos = board;
        int displacement = 0;
        convertTo1D( x, y, width, height, displacement );

        if( *( pos+displacement ) == checkValue )
        {

          count++;

        }
      }
    }
  }

  return count;

}

// Function to advance the board by one generation
void advance( char* board, int width, int height )
{

  char* advancedBoard = new char[ width*height ];
  copyBoard( advancedBoard, board, width, height );

  bool noChange = true;

  for( int yPos = 0; yPos < height; yPos++ )
  {

    for( int xPos = 0; xPos < width; xPos++ )
    {

      int displacement;
      int count = countNeighbors( board, xPos, yPos, width, height, 'O' );

      char* pos = advancedBoard;

      convertTo1D( xPos, yPos, width, height, displacement );
      pos = pos+displacement;

      // Rules of the game
      if( count < 2 && *pos == ALIVE )
      {

        *pos = '.';
        noChange = false;

      }else if( count <= 3 && *pos == ALIVE )
      {

        *pos = 'O';

      }else if( count > 3 && *pos == ALIVE )
      {

        *pos = '.';
        noChange = false;

      }else if( count == 3 && *pos == DEAD )
      {

        *pos = 'O';
        noChange = false;

      }
    } 
  }

  copyBoard( board, advancedBoard, width, height );
  delete[] advancedBoard;

  // If there is no change, place sentinel value in first position of board
  if( noChange )
  {
    
    *board = -1;
  
  }    
}

int main( int argc, char* argv[] ) 
{
  // Default generations to run is 100, but allow the user
  // to pass in a different value on the command line. Example:
  // ./a.out 50

  int generationsToRun = 100;
  int width;
  int height;

  if ( argc > 1 )
  {

    generationsToRun = atoi(argv[1]);

  }  

  cin >> width >> height;

  char* board = new char[ width * height ];

  for( int i = 0; i < width*height; i++ )
  {

    cin >> *( board+i );

  }
  
  // Printing the initial board
  cout << "\033[2J\033[1;1H";
  cout << "---STARTING BOARD---" << endl;
  printBoard( board, width, height );

  for( int i = 0; i < generationsToRun; i++ )
  {

    advance( board, width, height );
 
    // If sentinel value is found, end the simulation 
    if( *board == -1 )
    {

      break;

    }

    // Printing the board that has been iterated
    cout << "\033[1;1H";
    cout << "---GENERATION #" << i+1 << " ---" << endl;
    printBoard( board, width, height );

    usleep( 50000 );

  }

  delete[] board;
  
  return 0;

}

