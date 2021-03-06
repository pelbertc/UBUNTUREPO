/***********************************************************************
* This demo program is designed to:
*    Demonstration how to align multiple columns of numbers(money)
* Author:
*    Elbert Prescott
************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

/**********************************************************************
 * main (). Just one function for a simple program
  ***********************************************************************/
int main()
{
   //format the output for money
   cout.setf(ios::fixed);   //no scientific notation
   cout.setf(ios::showpoint); //always show the decimal point
   cout.precision(2);         //unless you own a gas station, money is formatted to 2 decimals

   //display the first row
   cout << "Item"
        << setw(11)
        << "\tProjected"
        << endl;
   
   //display the second row
   cout << "============="
        << setw(2) 
        << "=========="
        << endl;
   
   //display the third row
   cout << "Income"
        << setw(7)
        << "\t$"
        << setw(7) << 1000.0
        << endl;

   cout << "You will need to use '\\n' a ton in this class.\n";
   cout << "You will need to use \'\\n\' a ton in this class.\n";
   return 0;
}
