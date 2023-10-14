#include <iostream>
#include <string>

using namespace std;

class BankInfo {

	public:	
		void setUserInfo(int fileID[], string fileFirstName[],
						string fileLastName[], double fileSaving[], double fileChecking[]);

		void copyArray();

		void printCustomersData();

		void printNames();

		void printBankTotal();

		BankInfo();

	private:
		const static int arraySize = 10;
		int userID[arraySize];
		string userFirstName[arraySize];
		string userLastName[arraySize];
		string userFirstName1[arraySize];
		string userLastName1[arraySize];
		double userSaving[arraySize];
		double userChecking[arraySize];

};
