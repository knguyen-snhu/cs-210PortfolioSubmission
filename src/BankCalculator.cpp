/*
 * BankCalculator.cpp
 *
 *  Created on: Feb 5, 2020
 *      Author: Kevin Nguyen
 */

//Using stdio.h and string to help with printing/formating the chart
#include <stdio.h>
#include <iostream>
#include <string>
#include "BankCalculator.h"


BankCalculator::BankCalculator() {
}
//Get Interest uses the formula given for Bank App to calculate the total interest for each row
double BankCalculator::GetInterest(double t_openingAmount, int t_depositedAmount, double t_annualInterest) {
	return (t_openingAmount + t_depositedAmount) * ((t_annualInterest/100)/12);
}

//This function returns a character so that it may iterate through the input while loop in main if user decides to redo the chart
char BankCalculator::DisplayMonthBankChart(int t_month, double t_openingAmount, double t_depositedAmount, double t_totalAmount, double t_annualInterest, double t_closingAmount){
	//i is for iterating through each row, inputRedo is to return the char for main, openingBalance is set to the parameter so that is may be used for both charts
	int i = 0;
	char inputRedo;
	double openingBalance = t_openingAmount;

	//Using printf methods so that formatting/printing is cleaner and easier to handle
	printf("\n    BALANCE AND INTEREST WITH ADDITIONAL MONTHLY DEPOSITS    \n");
	std::cout << std::string(100,'=') << std::endl;
	printf("%s	|  %s  |  %s  |    %s    |   %s   |  %s\n", "MONTH", "OPENING AMOUNT", "DEPOSITED AMOUNT", "$TOTAL", "$INTEREST", "$CLOSING AMOUNT");

	 //For loops for each month
	for (i = 0; i < t_month; i++){
		//Initializing these 2 variables inside loop to prevents bugs and have a clean variable for each loop
		double closingBalance;
		double totalInterest;
		double totalAmount = openingBalance + t_depositedAmount;

		//Calling Class functions to get Interest and Closing Balance
		totalInterest = GetInterest(openingBalance, t_depositedAmount, t_annualInterest);
		closingBalance = GetClosingBalance(totalAmount, totalInterest);
		//Printing each variable using printf
		printf("%i   	    $%.2f	       $%.2f  		     $%.2f         $%.2f          $%.2f\n\n", (i + 1), openingBalance, t_depositedAmount, totalAmount, totalInterest,closingBalance);
		//Setting openingBalance to closingBalance so that the next row is calculated with previous values
		openingBalance = closingBalance;

		}

	//This begins the second chart without additional monthly deposits
	printf("\n    BALANCE AND INTEREST WITHOUT ADDITIONAL MONTHLY DEPOSITS    \n");
	std::cout << std::string(80,'=') << std::endl;
	printf("%s | %s  |    %s    |   %s   |  %s\n", "MONTH", "OPENING AMOUNT", "$TOTAL", "$INTEREST", "$CLOSING AMOUNT");

	//Setting openingBalance to the parameter again to reset it to original value
	openingBalance = t_openingAmount;

	//Copy of Loop above except without  monthly deposits
	for (i = 0; i < t_month; i++){
			double closingBalance;
			double totalInterest;
			double totalAmount = openingBalance;
			totalInterest = GetInterest(openingBalance, t_depositedAmount, t_annualInterest);
			closingBalance = GetClosingBalance(totalAmount, totalInterest);

			printf("%i	 $%.2f	  	    $%.2f	   $%.2f	   $%.2f\n\n", (i + 1), openingBalance, totalAmount, totalInterest,closingBalance);

			openingBalance = closingBalance;

		}
	//Asking for userinput to check if user would like to put in values again or quit
	printf("Would you like to change your Input Values?\n (Y= Input Values Again N= Quit)");
	std::cin >> inputRedo;
	//returning char for main to reiterate or quit
	return inputRedo;
}

//Functions is copy of Month functions except using year instead of months
//Calculations and prints are exactly the same as function above
char BankCalculator::DisplayYearBankChart(int t_year, double t_openingAmount, double t_depositedAmount, double t_totalAmount, double t_annualInterest, double t_closingAmount){

	int i = 0;
	char inputRedo;
	double openingBalance = t_openingAmount;

	printf("\n    BALANCE AND INTEREST WITH ADDITIONAL MONTHLY DEPOSITS    \n");
    std::cout << std::string(100,'=') << std::endl;
    printf("%s	|  %s  |  %s  |    %s    |   %s   |  %s\n", "YEAR", "OPENING AMOUNT", "DEPOSITED AMOUNT", "$TOTAL", "$INTEREST", "$CLOSING AMOUNT");

	for (i = 0; i < t_year; i++){
		double closingBalance;
		double totalInterest;
		double totalAmount = openingBalance + t_depositedAmount;
		totalInterest = GetInterest(openingBalance, t_depositedAmount, t_annualInterest);
		closingBalance = GetClosingBalance(totalAmount, totalInterest);

		printf("%i   	    $%.2f	       $%.2f  		     $%.2f         $%.2f          $%.2f\n\n", (i + 1), openingBalance, t_depositedAmount, totalAmount, totalInterest,closingBalance);

		openingBalance = closingBalance;

	}

	printf("\n    BALANCE AND INTEREST WITHOUT ADDITIONAL MONTHLY DEPOSITS    \n");
    std::cout << std::string(80,'=') << std::endl;
    printf("%s | %s  |    %s    |   %s   |  %s\n", "YEAR", "OPENING AMOUNT", "$TOTAL", "$INTEREST", "$CLOSING AMOUNT");

	openingBalance = t_openingAmount;


	for (i = 0; i < t_year; i++){
			double closingBalance;
			double totalInterest;
			double totalAmount = openingBalance;
			totalInterest = GetInterest(openingBalance, t_depositedAmount, t_annualInterest);
			closingBalance = GetClosingBalance(totalAmount, totalInterest);

			printf("%i	 $%.2f	  	    $%.2f	   $%.2f	   $%.2f\n\n", (i + 1), openingBalance, totalAmount, totalInterest,closingBalance);

			openingBalance = closingBalance;

		}

	printf("Would you like to change your Input Values?\n (Y= Input Values Again N= Quit)\n");
	std::cin >> inputRedo;
	return inputRedo;
}
//double GetClosingBalance Function to get the sum amount of each row
double BankCalculator::GetClosingBalance(double t_totalAmount, double t_interestAmount){
	return t_totalAmount + t_interestAmount;
}
