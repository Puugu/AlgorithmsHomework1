/********************************************************************************************************************************************
This project prompts the user for a number, then generates that many numbers (between 0 and 9999). It then provides the user a number
of different ways to sort through the numbers.

Creation Date: 2 Mar 2017
Created by Puugu

Edited: 22 March 2017
********************************************************************************************************************************************/

using namespace std;
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>

int getNumOfNums();
void genRanNums(const int userNum, string randNumOutputName, ofstream& randNumOutput);
int getSortSelection(int menuSortSelection);
bool insertionSort(string randNumInputName);

int main() {

	//declare and intialize variables, etc.
	int menuSortSelection = 0;
	bool fileExists = true;

	//display welcome message
	cout << "Welcome to Puugu's Random Number Sorter.\n"; 

	//get number of numbers to sort
	const int userNum = getNumOfNums();

	//generate data file
	string randNumIOName = "Data.txt";
	ofstream randNumOutput;

	//populate datafile with random numbers
	genRanNums(userNum, randNumIOName, randNumOutput);

	//get sort selection and sort data
	do {
		menuSortSelection = getSortSelection(menuSortSelection);
		switch (menuSortSelection) {
		case 1:
			cout << "Insertion Sort has been selected.\n\n";
			//call function for insertion sort
			fileExists =insertionSort(randNumIOName);
			break;
		case 2:
			cout << "Selection Sort has been selected.\n\n";
			break;
		case 3:
			cout << "Merge Sort has been selected.\n\n";
			break;
		case 4:
			cout << "Heapsort has been selected.\n\n";
			break;
		case 5:
			cout << "Quicksort has been selected.\n\n";
			break;
		case 6:
			cout << "Exit has been selected. Program will now terminate.\n\n";
			break;
		default:
			cout << "ERROR: Case " << menuSortSelection << " has not been accounted for. Program will now terminate.\n\n";
			menuSortSelection = 6;
		}
	} while ((menuSortSelection != 6) && (fileExists !=false));


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

void genRanNums(const int userNum, string randNumOutputName, ofstream& randNumOutput) {
	//This function generates the output file with the random numbers
	//Created by Puugu on 2 March 2017

	//declare and initialize variables, etc.
	int instanceNum = 0;

	//open output file
	randNumOutput.open(randNumOutputName);

	//first number is number of numbers
	randNumOutput << userNum << " ";

	/********************************************************
	generate random numbers for output file
	*********************************************************/
	for (int i = 0; i < userNum; i++) {
		instanceNum = rand() % 9999;
		randNumOutput << instanceNum << " ";
	}

	randNumOutput.close();

	return;
}

int getSortSelection(int menuSortSelection) {
	//this function shows the sort selection menu to the user
	//Created by Puugu on 22 March 2017

	//prompt user to select type of sort
	cout << "What type of sort would you like to perform?\n";
	cout << "1. Insertion Sort\n2. Selection Sort\n3. Merge Sort\n4. Heapsort\n5. Quicksort\n6. Exit\n";
	cout << "Please enter the number of your selection: ";
	cin >> menuSortSelection;
	cout << endl;
	//validate input
	while ((!cin) || (menuSortSelection<1) || (menuSortSelection>6)) {
		//clear error
		cin.clear();
		//flush input buffer
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//Tell user they have entered invalid data and prompt for re-entry
		cout << "ERROR: Your input was not valid. Please enter a numeric value between 1 and 6.\nWhich sort would you like to perform?: ";
		cin >> menuSortSelection;
		cout << endl;
	}

	//return menu selection
	return menuSortSelection;
}

bool insertionSort(string randNumInputName) {
	// this function performs the insertion sort and creates file for data output
	//created by Puugu on 22 March 2017

	//declare and initialize variables, etc.
	bool fileExists = false;
	int numOfNums = 0;
	time_t startTime;
	time_t endTime;
	int key = 0;
	int index = 0;
	float runTime = 0;

	//open input stream
	ifstream randNumInput(randNumInputName);
	//check to make sure input file exists
	if (!randNumInput) {
		cout << "ERROR: Input file could not be found.\nProgram will now terminate.\n\n";
		return fileExists = false;
	}
	else {
		fileExists = true;
	}

	//read first number from file to create array for sorting
	randNumInput >> numOfNums;
	//create array for sorting numbers
	int *sortingArray = new int[numOfNums];

	//populate array with random numbers
	for (int i = 0; i < numOfNums; i++) {
		randNumInput >> sortingArray[i];
	}

	//get start time
	startTime = time(0);

	//perform insertion sort
	for (int i = 1; i < numOfNums; i++) {
		key = sortingArray[i];
		index = i - 1;
		while ((index > 0) && (sortingArray[index] > key)) {
			sortingArray[index + 1] = sortingArray[index];
			index--;
		}
		sortingArray[index + 1] = key;
	}

	//get runtime
	endTime = time(0);
	runTime = (endTime - startTime);
	cout << "Timer: " << runTime << " seconds\nStart time: "<<startTime<<"\nEnd Time: "<<endTime<<endl;

	//create output stream
	ofstream sortedNums("insertionSort.txt");

	//write output for sorted file
	sortedNums << runTime << " ";
	for (int i = 0; i < numOfNums; i++) {
		sortedNums << sortingArray[i] << " ";
	}

	return fileExists;
}