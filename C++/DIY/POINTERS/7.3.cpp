#include <iostream>

using namespace std;

int main()
{
  double a = 1000;
  double b = 2000;
  double *p = &a;
  double *q = p;
  cout << "Value b " << b << endl;
  cout << "Pointer p " << p << endl;
  
  b = *q;
  p = &b;
  cout << "Pointer p " << p << endl;
  cout << "Value b " << b << endl;
  
  a = *p + *q;
  cout << a << " " << b << endl;
  
}
