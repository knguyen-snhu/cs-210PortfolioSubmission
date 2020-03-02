/*
 * BankCalculator.h
 *
 *  Created on: Feb 5, 2020
 *      Author: Kevin Nguyen
 */

#ifndef BANKCALCULATOR_H_
#define BANKCALCULATOR_H_

class BankCalculator {
public:
	BankCalculator();

//First function of Class is to get interest amount
	double GetInterest(double t_openingAmount, int t_depositedAmount, double t_annualInterest);
//Second Function is to display the Monthly Chart if user decides to use the Monthly Chart
	char DisplayMonthBankChart(int t_month, double t_openingAmount, double t_depositedAmount, double t_totalAmount, double t_annualInterest, double t_closingAmount);
//Third Function is to display the Annual Chart
	char DisplayYearBankChart(int t_year, double t_openingAmount, double t_depositedAmount, double t_totalAmount, double t_annualInterest, double t_closingAmount);
//Fourth Function is to get the Closing Balance of each row
	double GetClosingBalance(double t_totalAmount, double t_interestAmount);

};

#endif /* BANKCALCULATOR_H_ */
