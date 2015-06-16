#include <iostream>

using namespace std;

int main()
{

  int bob;
  int *andbob;
  int starbob;
  
  bob = 25;
  andbob = &bob;
  starbob = *andbob;

  cout << "bob: " << bob << endl
       << "andbob: " << andbob << endl
       << "starbob: " << starbob << endl;

  return 0;

}
