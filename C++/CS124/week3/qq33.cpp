#include <iostream>

using namespace std;

int main() {

  bool a = ('a' < 'a');

  cout << a << endl;

  bool b = ('b' > 'a');

  cout << b << endl;

  bool c = (a * 4) && b;

  cout << c << endl;
  
  bool d = !(b || (c || true));

  cout << d << endl;
  
  bool e = a && b && c && d;

  cout << e << endl;
  
  bool g = (a != b) && true;

  cout << g << endl;
  
}
