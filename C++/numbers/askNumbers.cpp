#include <iostream>

using namespace std;

int main()

{

int number1,number2;
char name1[256];
char name2[256];

cout << "Please enter your favorite number? ";

cin >> number1; 
cin >> number2;

cout << "What is your full name? ";

cin >> name1 >> name2;

cout << name1 << " " << name2 << endl;

cout << sizeof(char) << endl;
char a;
cout << sizeof(a) << endl;
cout << sizeof(bool) << endl;
int b;
cout << sizeof(b) << endl;
float c;
cout << sizeof(c) << endl;
double d;
cout << sizeof(d) << endl;
long double e;
cout << sizeof(e) << endl;

cout << "\\\"/\n" << endl;
return 0;

}
