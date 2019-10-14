#include <iostream>

using namespace std;

int main()
{
  double a = 1000;
  double b = 2000;
  double *p = &a;
  double *q = &b;
  cout << "*p " << *p << " &a " << &a << " *q " << &b << endl;
  *p = *q;
  cout << "*p " << *p << endl;
  p = q;
  cout << "p " << p << endl;
  *p = 3000;
  cout << "*p " << *p << endl;
  
}
