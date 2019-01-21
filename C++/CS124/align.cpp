#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  
cout << setw(13) << "Income" << "  $" << setw(9) << right << 1000.00 << endl;
cout << "\t" << setw(13) << left << "Taxes" << "  $" << setw(9) << right << 100.00 << endl;
cout << "\t" << setw(13) << left << "Tithing" << "  $" << setw(9) << right << 100.00 << endl;
cout << "\t" << setw(13) << left << "Living" << "  $" << setw(9) << right << 650.00 << endl;

 return 0;
}
