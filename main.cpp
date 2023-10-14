//Chad Huntebrinker
//crh92d@umsystem.edu
//12567690
//10/12/20


#include <iostream>
#include <fstream>
#include <iomanip>
#include "Class.h"

using namespace std;



int main() {
	BankInfo bank1;
	const int arraySize = 10;
	int fileID[arraySize];
	string fileFirstName[arraySize];
	string fileLastName[arraySize];
	double fileSaving[arraySize];
	double fileChecking[arraySize];
	char userInput ='c';
	int x = 0;
	ifstream fin;

	cout << fixed << setprecision(2);

	int tempID;
	string tempFirstName, tempLastName;
	double tempSaving, tempChecking;

	fin.open("program3input.txt");

	/*
	If the file fails to open, then the program will not run.
	This done by having userInput = Q which will cause the while loop on line 72 to quit.
	*/
	if (fin.fail()) {
		cout << "Failed to open file. Please try again." << endl;
		userInput = 'Q';
	}

	while (fin >> tempID && x < arraySize) {
		fin >> tempFirstName >> tempLastName;
		fin >> tempSaving >> tempChecking;
		fileID[x] = tempID;
		fileFirstName[x] = tempFirstName;
		fileLastName[x] = tempLastName;
		fileSaving[x] = tempSaving;
		fileChecking[x] = tempChecking;
		++x;
	}


	// This function is used to enter the information from the input file to the arrays

	bank1.setUserInfo(fileID, fileFirstName, fileLastName, fileSaving, fileChecking);

	/*
	This function is used to enter the first and last names of the bank customers into an identical
	array.  The reason for doing this is so that the original list of names doesn't get changed
	when the program needs to order the names alphabetically. Then we have the original array
	of names and an array ordered by their last name.
	*/
	bank1.copyArray();
	

	//This while loop is used so that when the user enters q/Q or if the file is 
	//not opened, the program exits.
	while (userInput != 'Q') {
		cout << "To print customer information, enter 1." << endl;
		cout << "To print all customers Names ordered by their Last Name, enter 2." << endl;
		cout << "To print Bank's total amount, enter 3." << endl;
		cout << "To quit, enter Q/q." << endl;
		cin >> userInput;

		switch (userInput) {
		case '1':
			bank1.printCustomersData();
			break;
		case '2':
			bank1.printNames();
			break;
		case '3':
			bank1.printBankTotal();
			break;
		case 'q':
		case 'Q':
			cout << endl;
			cout << "Goodbye" << endl;
			userInput = toupper(userInput);
			break;
		default:
			cout << endl;
			cout << "Invalid input. Please enter a number listed with one of the four options." << endl;
			cout << endl;
			break;
		}

	}


	fin.close();

	return 0;
}








