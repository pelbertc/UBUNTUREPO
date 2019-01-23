/***********************************************************************
* Program:
*    Project 03, Monthly Budget
*    Brother Wagstaff, CS124
* Author:
*    Elbert Prescott
* Summary:
*    prompts the user for his or her income and expenses and
*    displays the result on the screen.
*
*    Estimated:  3.0 hrs
*    Actual:     3.0 hrs
*    getting testbed and stylechekcer to pass was the hardest
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * getIncome() function will prompt the user for his income
 * and return the value to main():
 ***********************************************************************/
double getIncome(double monthlyIncome)
{
      //prompt
      cout << "\tYour monthly income: ";
      //get the value
      cin >> monthlyIncome;
      //return value to main
      return monthlyIncome;
}

double getBudgetLiving(double budgetLiving)
{
       //prompt
       cout << "\tYour budgeted living expenses: ";
       //get the value
       cin >> budgetLiving;
       //return value to main
       return budgetLiving;
}


double getActualLiving(double actualExpenses)
{
       //prompt
       cout << "\tYour actual living expenses: ";
       //get the  value
       cin >> actualExpenses;
       ///return value to main
       return actualExpenses;
}

double getActualTax(double actualTax)
{
	//prompt
	cout << "\tYour actual taxes withheld: "; 
	//get the value 
	cin >> actualTax;
	//return the value to main
	return actualTax;
}
double getActualTithing(double actualTithing)
{
        //prompt
        cout << "\tYour actual tithe offerings: ";
	//get the value	
	cin >> actualTithing;
	return actualTithing;
}
double getActualOther(double actualOther)
{
	cout << "\tYour actual other expenses: ";
	//double actualOther;
	cin >> actualOther;
	return actualOther;
}

double display(double income, double actualTax, double actualTithing, double actualLiving, double actualOther, double budgetLiving )
{
  
  // return 0;
  
  //Line 1
  cout << "The following is a report on your monthly expenses\n";

  //Line 2
  cout << "\tItem" << setw(24) << "Budget" << setw(17) << "Actual\n";

  //Line 3
  cout << "\t=============== " << "===============" << " ===============\n";

  //Line 4
  cout << "\tIncome" << setw(11) << "$" << setw(11) << income
       << setw(5) << "$" << setw(11) << income << endl;

  //Line 5
  cout << "\tTaxes" << setw(12) << "$" << setw(11) << 0.00
       << setw(5) << "$" << setw(11) << actualTax << endl;

  //Line 6
  cout << "\tTithing" << setw(10) << "$" << setw(11) << 0.00
       << setw(5) << "$" << setw(11) << actualTithing << endl;

  //Line 7
  cout << "\tLiving" << setw(11) << "$" << setw(11) << budgetLiving
       << setw(5) << "$" << setw(11) << actualLiving << endl;

  //Line 8
  cout << "\tOther" << setw(12) << "$" << setw(11) << 0.00
       << setw(5) << "$" << setw(11) << actualOther << endl;

  //Line 9
  cout << "\t=============== " << "===============" << " ===============\n";

  //Differences between dugdet and actuals

  cout << "\tDifference" << setw(7) << "$" << setw(11) << 0.00
       << setw(5) << "$" << setw(11) << 0.00 << endl;

}

/**********************************************************************
 * MAIN
 * The main function will prompts the user for his or her income and
 * expenses and will displays on the screen.
 ***********************************************************************/
int main()
{
   //format the output for money
   cout.setf(ios::fixed);   //no scientific notation
   cout.setf(ios::showpoint); //always show the decimal point
   cout.precision(2);         //money is formatted to 2 decimals

   //Declare variable
   double monthlyIncome;
   double budgetExpenses;
   double actualExpenses;
   double actualTaxes;
   double actualTithes;
   double otherExpenses;
   

   //Greeting Line
   cout << "This program keeps track of your monthly budget\n";

   //Request information Line
   cout << "Please enter the following:\n";

   //Call monthly income function
   double income = getIncome(monthlyIncome);
     
   double budgetLiving = getBudgetLiving(budgetExpenses);
   
   double actualLiving = getActualLiving(actualExpenses);
   
   double actualTax = getActualTax(actualTaxes);
   
   double actualTithing = getActualTithing(actualTithes);
   	
   double actualOther = getActualOther(otherExpenses);

   display(income,actualTax,actualTithing,actualLiving,actualOther,budgetLiving);
   
   return 0;

}
