#ifndef COUNTY_H
#define COUNTY_H

#include <string>

using namespace std;

class County
{

private:
  string countyName;
  string stateName;

  int rVote;
  int dVote;
  int oVote;

public:
  County( string countyName, string stateName, int rVote, int dVote, int oVote );
  County( string line, string stateName );

  virtual ~County();

  string getCountyName();
  string getStateName();

  int getRVote();
  int getDVote();
  int getOVote();

};

#endif
