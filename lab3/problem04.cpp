#include <iostream>

using namespace std;

int main()
{

  int pennies = 0;
  int nickels = 0;
  int dimes = 0;
  int quarters = 0;
  int sum = 0;

  cout << "Welcome to the change-for-a dollar game!" << endl
       << "Enter the number of quarters you have: ";
  cin >> quarters;
  cout << "Enter the number of dimes you have: ";
  cin >> dimes;
  cout << "Enter the number of nickels you have: ";
  cin >> nickels;
  cout << "Enter the number of pennies you have: ";
  cin >> pennies;

  sum = pennies+( 5*nickels )+( 10*dimes )+( 25*quarters );
  
  if( 25*quarters >= 100 || 10*dimes >= 100 || 5*nickels >= 100 || pennies >= 100 ||
      quarters <= 0 || dimes <= 0 || nickels <= 0 || pennies <= 0 )
  {
    
    cout << "You must have at least 1 of each coin and less than 1 dollar of that coin type" << endl;

  }else if( sum < 100 )
  {

    cout << "You lose, your total of " << sum << " cents is less than 1 dollar." << endl;

  }else if( sum == 100 )
    
    cout << "You win! The total adds up to 1 dollar!" << endl;
}

