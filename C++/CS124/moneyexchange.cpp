#include <iostream>

using namespace std;

int main()
{
  //get user input
  cout << "Please enter a positive dollar amount($3.23): ";
  double dollars;
  cin >> dollars;

  //conver it from dollars to cents
  int cents = (int)(dollars * 100.00);

  //DOLLARS
  cout << "\t(100c)Dollars:   " << cents / 100 << endl;
  cents %= 100;

  //QUARTERS
  cout << "\t(25c)Quarters:   " <<  cents / 25 << endl;
  cents %= 25;

  //DIMES
  cout << "\t(10c)Dimes:   " << cents / 10 << endl;
  cents %= 10;

  //NICKLES
  cout << "\t(5c)Nickles:   " << cents / 5 << endl;
  cents %= 5;
					 
   //PENNIES
  cout << "\t(1c)Pennies:   " << cents << endl;
  
  return 0;

}
