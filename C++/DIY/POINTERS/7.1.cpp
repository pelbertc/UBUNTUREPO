#include <iostream>

using namespace std;

int main()
{
  double a = 1000;
  double b = 2000;
  double *p = &a;
  cout << "*p " << *p << " &a " << &a << endl;
  *p = 3000;
  cout << "*p " << *p << endl;
  p = &b;
  cout << "p " << p << endl;
  a = *p * 2;
  cout << "a " << a << endl;
  
}
