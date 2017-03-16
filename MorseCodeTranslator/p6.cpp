//p6.cpp

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

#include "Translator.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
	
	int myChoice;
	string mySentence;
	Translator trans("MorseCodes.txt");
	
	
	cout << "Please choose one of the available options:\n\n" << "1 - Translate Morse to Character\n" << "2 - Translate Character to Morse\n" <<"3 - Display Morse to Character Key\n" << "4 - Display Character to Morse Key\n" << "5 - Exit Program\n\n";
	cout << "Please enter 1-5" << endl;
	cin >> myChoice;
	
	//choice 1
	if (myChoice == 1){
		cout << "Please enter a sentence: " << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		getline(cin, mySentence, '\n');
		string dummy = trans.TranslateMorseToChar(mySentence);
		cout << "What you entered in morse code was:  " << dummy;
		cout << endl << endl;
	}
	//choice 2
	else if (myChoice == 2){
		cout << "Please enter a sentence: (in capital letters)" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		getline(cin, mySentence, '\n');
		vector<string> dummy = trans.TranslateCharacterToMorse(mySentence);
		cout << "In morse code, what you entered is translated into: " << endl;
		for ( size_t j = 0; j<dummy.size(); j++){
			cout << dummy[j] << endl;
		}
		cout << endl << endl;
	}
	//choice 3
	else if (myChoice == 3){
		trans.DisplayMorseToCharKey();
		cout << endl << endl;
	}
	//choice 4
	else if (myChoice == 4) {
		trans.DisplayCharToMorseKey();
		cout << endl << endl;
	}
	//choice 5
	else if (myChoice == 5) {
		cout << "You have chosen to quit. Good bye." << endl;
		return 0;
	}
	//default
	else{
		cout << "This is not a valid choice. Please try again." << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	
}
}
