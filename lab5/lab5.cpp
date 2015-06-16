#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Rolls a 1d6 die
int rollDie()
{

  int dieValue = ( rand()%6 )+1;

  return dieValue;

}

// Game logic for one single iteration of the game
bool playOneGame()
{

  int point = 0; // Value that the die must land on

  cout << "Enter your point value (1 - 6): ";
  cin >> point;
  
  // Checking for valid point value
  while( point <= 0 || point > 6 )
  {

    cout << "Error: Enter your point value, must be between 1 and 6: ";
    cin >> point;

  }

  // For loop to roll the dice and check if it landed on the point
  for( int i = 0; i < 3; i++ )
  {

    int dieValue = rollDie();

    cout << "Roll #" << i+1 << " is " << dieValue << endl;

    if( dieValue == point )
    {
      
      // If it does land, function returns true
      cout << " ** You win! ** " << endl;
      return true;

    }else if( i == 2 )
    {  
     
      // If it gets to the third iteration without landing, then return false
      cout << " ** You lose ** " << endl;
      return false;

    }                 
  }
} 

// Displays balance
void display( int balance )
{

  cout << "$" << balance;

}

int main()
{

  double balance = 100.00;
  double wager = 0.00;

  // Seed random
  srand( time( NULL ));
  
  // While the user still has money to spend, let them keep playing
  while( balance > 0 )
  {

    cout << endl
         << "Account balance ";
    display( balance );
    cout << endl
         << "Enter wager (0 to exit): $";
    cin >> wager;
    
    // Checking for a valid wager value
    while( wager > balance || wager < 0 )
    {

      cout << "Error: You must wager between $1 and ";
      display( balance ); 
      cout << " (type 0 to exit): $";
      cin >> wager;

    }

    // If wager is 0, end the game
    if( wager == 0 )
    {
      break;
    }
  
    // If they win the game, increase balance by their wager, otherwise, deduct balance by wager
    if( playOneGame() )
    {

      balance += wager;

    }else
    {

      balance -= wager;

    }
  }

  // Gamer over man, game over!
  if( balance == 0 )
  {

    cout << "Game over, you are out of money!" << endl;

  }

  cout << "Your final account balance is: ";
  display( balance );
  cout << endl;

  return 0;
}
