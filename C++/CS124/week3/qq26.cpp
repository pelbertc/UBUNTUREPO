#include <iostream>
using namespace std;

void setTrue(bool a)
{
  a = true;
  return;
}

int main()
{
  bool a = false;

  setTrue(a);

  cout << (int)a << endl;

  return 0;
}
