#include <string>
#include <sstream>
#include <stdlib.h>

using namespace std;

#include <County.h>

County::County( string countyName, string stateName, int rVote, int dVote, int oVote )
{

  this->countyName = countyName;
  this->stateName = stateName;
  this->rVote = rVote;
  this->dVote = dVote;
  this->oVote = oVote;

}

County::County( string line, string stateName )
{

  this->stateName = stateName;

  string token;
  stringstream ss( line );
      
  getline( ss, token, ',' );
  countyName = token;

  getline( ss, token, ',' );
  rVote = atoi( token.c_str() );

  getline( ss, token, ',' );
  dVote = atoi( token.c_str() );

  getline( ss, token, ',' );
  oVote = atoi( token.c_str() );

  if( stateName == "LA" )
  {
    
    countyName += " Parish";
  
  }
}

County::~County()
{

  return;

}

string County::getCountyName()
{

  return countyName;

}

string County::getStateName()
{

  return stateName;

}

int County::getRVote()
{

  return rVote;

}

int County::getDVote()
{

  return dVote;

}

int County::getOVote()
{

  return oVote;

}

