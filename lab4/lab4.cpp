#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

  int count = 1; // fill-up count
  int miles = 0;
  int odometer = 0; // input odometer
  int odometerOld = 0; // temp value for odometer
  int odometerInitial = 0; // initial reading

  double gallons = 0;
  double gallonsTotal = 0;
  double cost = 0;
  double costTotal = 0;
  double mpg = 0; // miles per gallon
  double dpg = 0; // dollars per gallon
  double mpd = 0; // miles per dollar

  // Initial odometer reading
  cout << "This program will calculate an automobile's gas mileage statistics." << endl
       << "Enter initial odometer reading: ";
  cin >> odometerInitial;
  odometer = odometerInitial;

  // Main program loop
  while( true )
  {

    // Gallons input, if negative, end loop
    cout << "Fill-up #" << count << endl
         << "Enter gallons used (negative number to end): ";
    cin >> gallons;
    if( gallons < 0 )
    {

      break;

    }
    gallonsTotal = gallonsTotal+gallons;

    // Price input
    cout << "Enter price paid: $";
    cin >> cost;
    costTotal = costTotal+cost;

    // Odometer input
    odometerOld = odometer;
    cout << "Enter new odometer reading: ";
    cin >> odometer;
    miles = odometer-odometerOld;

    // Stats calculations
    mpg = miles/gallons;
    dpg = cost/gallons;
    mpd = miles/cost;

    // Stats output
    cout << "Stats for fill-up #" << count << endl
         << " * " << miles << " miles" << endl
         << " * " << setprecision( 1 ) << fixed << mpg << " miles per gallon" << endl
         << " * " << "$" << setprecision( 2 ) << fixed << dpg << " per gallon" << endl
         << " * " << setprecision( 2 ) << fixed << mpd << " miles per dollar" << endl
         << endl;

    count++;

  }

  // Final stats calcuations, based on the total values
  miles = odometer-odometerInitial;
  mpg = miles/gallonsTotal;
  dpg = costTotal/gallonsTotal;
  mpd = miles/costTotal;

  // Final stats output
  cout << "Final statistics: After " << count << " fill-ups." << endl
       << " * " << miles << " miles" << endl
       << " * " << setprecision( 1 ) << fixed << mpg << " miles per gallon" << endl
       << " * " << "$" << setprecision( 2 ) << fixed << dpg << " per gallon" << endl
       << " * " << setprecision( 2 ) << fixed << mpd << " miles per dollar" << endl
       << endl;

  // So long, and thanks for all the fish
  cout << "Goodbye!" << endl;
  return 0;

}

