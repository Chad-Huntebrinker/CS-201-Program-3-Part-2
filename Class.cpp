#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Class.h"

using namespace std;

//Default Constructor

BankInfo::BankInfo() {
	int userID[arraySize] = { 0,0,0,0,0,0,0,0,0,0 };
	string userFirstName[arraySize] = { "None" };
	string userLastName[arraySize] = { "None" };
	string userFirstName1[arraySize] = { "None" };
	string userLastName1[arraySize] = { "None" };
	double userSaving[arraySize];
	double userChecking[arraySize] = { 0,0,0,0,0,0,0,0,0,0 };
}

/*
The purpose of this function is to get the information from the main program and put into the
variables in the class.
*/
void BankInfo :: setUserInfo(int fileID[], string fileFirstName[],
	string fileLastName[], double fileSaving[], double fileChecking[]) {
	int x;
	for (x = 0; x < arraySize; ++x) {
		userID[x] = fileID[x];
		userFirstName[x] = fileFirstName[x];
		userLastName[x] = fileLastName[x];
		userSaving[x] = fileSaving[x];
		userChecking[x] = fileChecking[x];
	}
}

/*
This function is used to enter the first and last names of the bank customers into an identical
array.  The reason for doing this is so that the original list of names doesn't get changed
when the program needs to order the names alphabetically. Then we have the original array
of names and an array ordered by their last name.
*/
void BankInfo::copyArray() {
	for (int x = 0; x < arraySize; ++x) {
			userFirstName1[x] = userFirstName[x];
			userLastName1[x] = userLastName[x];
		}

}


//The purpose of this function is to output the information from the file in a neat and orderly way

void BankInfo :: printCustomersData() {

	int x = 0;

	cout << endl;
	cout << "Last Name , First Name , ID , Saving Account , Checking Account" << endl;
	cout << setfill('-') << setw(63) << "" << endl;
	cout << setfill(' ');
	do {
		cout << setw(9) << userLastName[x] << " , ";
		cout << setw(10) << userFirstName[x] << " , ";
		cout << setw(3) << userID[x] << ", ";
		cout << setw(16) << userSaving[x] << " , ";
		cout << setw(14) << userChecking[x] << endl;

		++x;
	} while (x < arraySize);
	cout << setfill('-') << setw(63) << "" << endl;
	cout << setfill(' ') << endl;

}

/*
The purpose of this function is to list the names of the customers in the bank in alphabetical order by their
their last name.  If their last name is the same, it then compares it with the first name.
 */
void BankInfo :: printNames() {
	int i = 0, x;
	string temp1, temp2;
	for (i = 1; i < arraySize; ++i) {
		x = i;
		while (x > 0 && userLastName1[x] < userLastName1[x - 1]) {
			temp1 = userLastName1[x];
			userLastName1[x] = userLastName1[x - 1];
			userLastName1[x - 1] = temp1;
			temp2 = userFirstName1[x];
			userFirstName1[x] = userFirstName1[x - 1];
			userFirstName1[x - 1] = temp2;
			--x;
			if (userLastName1[x] == userLastName1[x - 1] && userFirstName1[x] < userFirstName1[x - 1]) {
				temp1 = userLastName1[x];
				userLastName1[x] = userLastName1[x - 1];
				userLastName1[x - 1] = temp1;
				temp2 = userFirstName1[x];
				userFirstName1[x] = userFirstName1[x - 1];
				userFirstName1[x - 1] = temp2;
			}
		}
	}
	cout << endl;
	cout << "Last Name  , First Name" << endl;
	cout << setfill('-') << setw(22) << "" << endl;
	cout << setfill(' ');


	for (i = 0; i < arraySize; ++i) {
		cout << setw(10) << userLastName1[i] << " , " << setw(9) << userFirstName1[i] << endl;
	}
	cout << setfill('-') << setw(22) << "" << endl;
	cout << setfill(' ') << endl;
}


//The purpose of this function is to print the total of the bank's savings and checking account

void BankInfo :: printBankTotal() {
	double temp1, temp2, savingTotal = 0, checkingTotal = 0;
	int i;

	for (i = 0; i < arraySize; ++i) {
		temp1 = userSaving[i];
		temp2 = userChecking[i];
		savingTotal = temp1 + savingTotal;
		checkingTotal = temp2 + checkingTotal;
	}
	cout << setfill('-') << setw(62) << "" << endl;
	cout << setfill(' ');
	cout << "Bank Savings total is " << savingTotal << " and Checking total is " << checkingTotal << endl;
	cout << setfill('-') << setw(61) << "" << endl;
	cout << setfill(' ') << endl;
}