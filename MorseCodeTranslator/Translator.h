//Translator.h

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

#ifndef TRANSLATOR_H
#define TRANSLATOR_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <iterator>
using namespace std;

class Translator{
	//everything here is as described in the assignment
	private:
	
		ifstream morseKey; //file object
		map< char, string, less<char> > charToMorse; //map charToMorse
		map< string, char, less<string> > morseToChar; //map morseToChar
		
	public:
	
		Translator(string ); //constructor
		vector<string> TranslateCharacterToMorse( string );
		string TranslateMorseToChar ( string );
		void DisplayCharToMorseKey();
		void DisplayMorseToCharKey();
		
	};
	#endif
		
