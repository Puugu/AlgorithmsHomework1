/********************************************************************************************************************************************
This project prompts the user for a number, then generates that many numbers (between 0 and 9999). It then provides the user a number
of different ways to sort through the numbers.

Creation Date: 2 Mar 2017
Created by Puugu

Edited: 
********************************************************************************************************************************************/

using namespace std;
#include <iostream>
#include <fstream>
#include <ctime>

int getNumOfNums();
bool genRanNums(const int userNum, string randNumOutputName, ofstream& randNumOutput);

int main() {

	//display welcome message
	cout << "Welcome to Puugu's Random Number Sorter.\n"; 

	//get number of numbers to sort
	const int userNum = getNumOfNums();

	//generate data file
	string randNumOutputName = "Data.txt";
	ofstream randNumOutput;

	if (genRanNums(userNum, randNumOutputName, randNumOutput)) {
		cout << "Yay\n";
	}
	else {
		cout << "BOO\n";
	}


	system("pause");
	return 0;
}

int getNumOfNums() {
	//This function gets the number of numbers to sort from the user
	//Created by Puugu on 2 March 2017

	//declare and initialize variables
	int userNum = 0;

	//prompt user to get # of #s to sort
	cout << "To start, how many numbers would you like to sort ? : ";
	cin >> userNum;
	cout << endl;
	//validate input
	while ((!cin) || (userNum<1) || (userNum>9999)) {
		//clear error
		cin.clear();
		//flush input buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//Tell user they have entered invalid data and prompt for re-entry
		cout << "ERROR: Your input was not valid. Please enter a numeric value between 1 and 9999.\nHow many numbers would you like to sort?: ";
		cin >> userNum;
		cout << endl;
	}

	//return # of #s and exit function
	return userNum;
}

bool genRanNums(const int userNum, string randNumOutputName, ofstream& randNumOutput) {
	//This function generates the output file with the random numbers
	//Created by Puugu on 2 March 2017

	//declare and initialize variables, etc.
	bool success = false;

	//open output file
	randNumOutput.open(randNumOutputName);

	/********************************************************
	generate random numbers for output file
	*********************************************************/

	return success;
}