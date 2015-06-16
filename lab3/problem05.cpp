#include <iostream>

using namespace std;

int main()
{

  int seconds = 0;
  int remainder = 0;
  int minutes = 0;
  int hours = 0;
  int days = 0;

  char format;

  cout << "Enter the number of seconds: ";
  cin >> seconds;
  cout << "Do you want this converted to (m)inutes, (h)ours, or (d)ays? ";
  cin >> format;

  if( format == 'm' )
  {
    
    minutes = seconds/60;
    seconds = seconds-( 60*minutes );

    cout << minutes << " minutes " << seconds << " seconds." << endl;

  }else if( format == 'h' )
  {
    
    hours = seconds/3600;
    seconds = seconds-( hours*3600 );
    minutes = seconds/60;
    seconds = seconds-( minutes*60 );

    cout << hours << " hours, " << minutes << " minutes " << seconds << " seconds." << endl;

  }else if( format == 'd' )
  {

    days = seconds/86400;
    seconds = seconds-( days*86400 );
    hours = seconds/3600;
    seconds = seconds-( hours*3600 );
    minutes = seconds/60;
    seconds = seconds-( minutes*60 );

    cout << days << " days, " << hours << " hours, " << minutes << " minutes." << seconds << " seconds." << endl;

  }

}
