#include <iostream>

using namespace std;



int main()
{
  {
    char a[] = "software";
       bool b[] =
	 { false, true, false, false,
	   false, true, false, true };

       for (int i = 0; i < 8; i++)
	 if (b[i])
	   cout << a[i];
  }
}

/*
int main()
{
  
    char x = 'a';

    if (x > 'b');
    x = 'c';

    cout << x << endl;
  
    int i = 0;
    for (int j = 2; j < 7; j += 2)
      i++;
    cout << i << endl;

    int a = 0;
    for (int b = 1; b < 6; b++)
      a += b;
    cout << a << endl;

    int k = 1;
    while (k < 3)
      k++;

    cout << k << endl;
}
  
*/
