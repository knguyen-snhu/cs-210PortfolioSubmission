//============================================================================
// Name        : Kevin_Nguyen_Airgead_Bank_App.cpp
// Author      : Kevin Nguyen
// Description : Bank App
//============================================================================

//included BankCalculator because it is the class I created for the Bank Chart
#include <iostream>
#include "BankCalculator.h"
using namespace std;

//Used Global Variables for ease of use with functions
double initialInvestment;
int monthDeposit;
double annualInterest;
int inputTime;
//inputRedo is for reiterating if user would like to re-input values and inputBankDisplay for Month/Year option
char inputRedo = 'Y';
char inputBankDisplay;


//This function is used to display the input menus for the user
void DisplayDataInputMenu(){


	if ((inputBankDisplay == 'y') || (inputBankDisplay == 'Y' )){
		cout << "**************************************" << endl;
		cout << "*************" << " Data Input " << "*************" << endl;
		cout << "Initial Investment Amount: $" << initialInvestment << endl;
		cout << "Monthly Deposit: $" << monthDeposit << endl;
		cout << "Annual Interest: %" << annualInterest << endl;
		cout << "Number of Years: " << inputTime << endl;
		cout << "Press Enter to continue . . ." << endl;

		//System Read if to wait for user to press Enter to continue

		system("read");
		}

	else{
		cout << "**************************************" << endl;
		cout << "*************" << " Data Input " << "*************" << endl;
		cout << "Initial Investment Amount: $" << initialInvestment << endl;
		cout << "Monthly Deposit: $" << monthDeposit << endl;
		cout << "Annual Interest: %" << annualInterest << endl;
		cout << "Number of Months: " << inputTime << endl;
		cout << "Press Enter to continue . . ." << endl;

		//System Read if to wait for user to press Enter to continue
		system("read");
		}
}

int main() {

//Ask if user would like to use Monthly or Annual Chart
	cout << "Would you like to see an Annual Bank Chart or a Monthly Bank Chart?\n (Y= Annual N= Monthly)" << endl;
	cin >> inputBankDisplay;

	//Creating BankCalculator Object
	BankCalculator bankCalculator;
	//While loop for user to continually re-input values until user decides to quit
	while ((inputRedo == 'y') || (inputRedo == 'Y')){
		if ((inputBankDisplay == 'y') || (inputBankDisplay == 'Y')){
			cout << "IntialInvestment: " << endl;
			cin >> initialInvestment;
			cout << "Monthly Deposit: " << endl;
			cin >> monthDeposit;
			cout << "Annual Interest: " << endl;
			cin >> annualInterest;
			cout << "Number of Years: " << endl;
			cin >> inputTime;
			DisplayDataInputMenu();
			//Setting as inputRedo to wait for user to input char for reinputing values or quitting
			inputRedo = bankCalculator.DisplayYearBankChart(inputTime, initialInvestment, monthDeposit, 0, annualInterest, 0);

			}
//Else if for Monthly input values if user chooses
		else {
			cout << "IntialInvestment: " << endl;
			cin >> initialInvestment;
			cout << "Monthly Deposit: " << endl;
			cin >> monthDeposit;
			cout << "Annual Interest: " << endl;
			cin >> annualInterest;
			cout << "Number of Years: " << endl;
			cin >> inputTime;
			inputTime = inputTime * 12;
			DisplayDataInputMenu();
			//Setting as inputRedo to wait for user to input char for reinputing values or quitting
			inputRedo = bankCalculator.DisplayMonthBankChart(inputTime, initialInvestment, monthDeposit, 0, annualInterest, 0);

			}

	}


	return 0;
}
