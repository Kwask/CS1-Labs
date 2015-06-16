//*************************************************************
//
//Title: An easily upsettable riddle.
//Author: Charles Hirzel
//CS1021-001 Date: January 13, 2014
//Laboratory 1
//
//*************************************************************
//
//Description: This programs asks the user a fairly simple riddle, so don't try to push it too far.
//
//Input: Only from user when prompted.
//
//Output: Displays clues and the riddle to the user.
//
//Procedure: The instructions will be layed out on-screen when the program is started. Just state "Clue" if you want a clue or "Riddle" if you want 
//to hear the riddle again.
//
//Constraints: The riddle should have at least two clues and should be G-rated.
//
//************Begin Program************************************

#include <iostream>
#include <string>

using namespace std;

// Main function
int main()
{

	// Declaring the variables needed to run the program
	int clueNumber = 0;
	int wrongNumber = 0;
	
	// The list of replies from the program
	string clues[ 11 ]      = { "I give life to all things.",
	       		   	    "I do not plan on leaving for billions of years.",
      				    "I Start and I eNd",
				    "I am the fire that never shows in the night.",
				    "I am the brightest light you've ever seen.",
			            "Ok, this isnt that hard, my name is three letters long.",
				    "Seriously? That should have been as obvious as the sun in the sky!",
				    "Ok, really? You couldn't get the answer from that? The answer is Sun.",
				    "What is wrong with you?! This was supposed to be a fun game, but you've taken it too far.",
				    "You're a sociopath is what you are, you dont think the rules apply to you!",
				    "Thats it, I'm done talking to you." };
	string whatWasThat[ 5 ] = { "What was that?", 
				    "Excuse me?", 
				    "Speak up, please.", 
				    "What did you say?", 
				    "How does that make any sense?" };
	
	// The input variable for the user, set at "Riddle" by default so it asks the program for the riddle on startup
	string input = "Riddle";

	// Tracks whether the riddle is solved, and if the program is upset
	bool solved = false;
	bool upset  = false;

	// A while loop so that the user can have multiple tries
	while( solved == false )
	{

		if( input == "Riddle" or input == "riddle" and upset == false  )
		{
			// The riddle itself.
			cout << "If I were to disappear, so would you." << endl
			     << "What am I?" << endl;
			input = "";

		}else if( input == "Clue" or input == "clue" and upset == false )
		{
		
			// If the user asks for a clue
			cout << clues[ clueNumber ] << endl;

			if( clueNumber == 10 )
			{
				// If the user asks for too many clues
				upset = true;

			}else
			{
			
				clueNumber++;
			
			}
		
			input = "";

		}else if( input == "Sun" or input == "sun" )
		{
			// Varying reply based on the mood of the program
			if( upset == false )
			{
			
				cout << "Congratulations, thats the correct answer!" << endl;
			
			}else if( upset == true )
			{
		
				cout << "Good job, you got the answer after I told it to you, now please go away." << endl;	

			}
		
			solved = true;

		}
		else if( input != "" and upset == false )
		{
			// If the user inputs an unrecognized string
			cout << whatWasThat[ wrongNumber ] << endl;

			wrongNumber = ( wrongNumber+1 )%4;
			input = "";
		
		}

		if( solved == false and upset == false )
		{

			cout << "Do you want to hear the riddle again, or do you want a clue?" << endl;
		
		}else if(  solved == false and upset == true )
		{
			// If the program is upset, it won't say anything to the user
			cout << "..." << endl;
		
		}	
		if( solved == false )
		{
			// Gets the input from the user as ong as the riddle isnt solved
			cin >> input;
		
		}

	}
	
	return 0;

}
