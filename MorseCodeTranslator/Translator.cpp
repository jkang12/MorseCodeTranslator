//Translator.cpp

/*

Course Number:  1342
Programmer:     Joseph Kang
Date:           12/7/2015
Program Number: Program 6
Purpose:        Translates morse code into English and vice versa
Server:         genuse30.lyle.smu.edu
Instructor:     Donald Evans
TA:             Sean

 

Sources Consulted: only the textbook

*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include "Translator.h"
#include <algorithm>
#include <iterator>
#include <iterator>
using namespace std;

Translator::Translator(string myStr ){
	ifstream morseKey(myStr, ios::in); //re-construct the file object
	if (!morseKey){ //check to see if the file is open-able
		cerr<< "File could not be opened" << endl;
		exit( EXIT_FAILURE );
	}
	string dumS;
	char dumC;
	while (!morseKey.eof())
	{
		morseKey >> dumC >> dumS; //input the char's and strings from the .txt file
		charToMorse.insert( make_pair (dumC, dumS) );
		morseToChar.insert( make_pair (dumS, dumC) );
	}
}

vector<string> Translator::TranslateCharacterToMorse( string myStr ){
	char myChar;
	vector< string > myVector;
	for( size_t i = 0; i < myStr.size(); i++ ){
		if( myStr[i] != ' ' ){ //input everything except spaces
			myChar = myStr[i];
			string location = charToMorse[myChar]; // get the corresponding string of Morse code from the map
			myVector.push_back(location); //push that string into the back of the vector to return
		}
		else{ //ignore spaces
			string location = ""; //input an empty string into the return vector
			myVector.push_back(location);
			
		}
	}
	return myVector;
}

string Translator::TranslateMorseToChar( string myStr ){
	vector<string> dumVec;
	string returnString;
	size_t i = 0;
	string dumStr;

	
	char myChar;
	for ( size_t j = 0; j <= myStr.size(); ++j ){
		if (myStr[j] != ' ' && myStr[j] != '\0'){ //input everything except spaces and eof
			myChar = myStr[j];
			dumStr.push_back(myChar); //treating string like a regular vector
		}
		else{ //ignore spaces and eof
			
			dumVec.push_back(dumStr);
			dumStr.clear();
			dumStr.shrink_to_fit();
			
		}
		
	}
	
	
	for (size_t z = 0; z < dumVec.size(); z++){
		string temp = dumVec[z]; //read the individual strings that we inputted into this vector above
		char location = morseToChar[temp]; //get the corresponding alphabet from the map
		returnString.push_back(location); //build the string to return
	}
	return returnString;
}

void Translator::DisplayCharToMorseKey(){
	
	cout << "Map charToMorse contains: \nKey\tValue\n";
	for( auto mapItem : charToMorse )
		cout << mapItem.first << '\t' << mapItem.second <<endl;
	}
	
void Translator::DisplayMorseToCharKey(){
	cout << "Map morseToChar contains: " << endl <<"Key\tValue"<<endl;
	for ( auto mapItem : morseToChar ){
		cout << mapItem.first << '\t' << mapItem.second << endl;
	}
	}	
