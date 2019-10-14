#include <iostream>
using namespace std;

bool isEqual(char *text1, char *text2)
{
  int i;
  for(i = 0;
      text1[i] == text2[i] &&
      text1[i] && text2[i];
      i++)
    ;
  return(text1[i] == text2[i]);
}

int main()
{
  char text1[10] = {};
  char text2[10] = {};
  cout << "Please enter text1: ";
  cin >> text1;
  cout << "Please enter text2: ";
  cin >> text2;
  
  cout << "Cout 1 for true or 0 for false:   " << isEqual(text1,text2) << endl;
  
}
