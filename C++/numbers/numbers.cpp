#include <iostream>
#include <iomanip>

using namespace std;

int main(){

        //format the output for money
        cout.setf(ios::fixed);   //no scientific notation
        cout.setf(ios::showpoint); //always show the decimal point
        cout.precision(2);         //money is formatted to 2 decimals
	
	cout << "BIll:" << endl;
         
	cout << "\t$" << setw(6) << 10.00 << " - " << "Price" << endl;
	cout << "\t$" << setw(6) << 1.50 << " - " << "Tip" << endl;
	cout << "\t$" << setw(6) << 11.50 << " - " << "Total" << endl;
	return 0;

}
