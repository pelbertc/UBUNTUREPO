#include <iostream>

using namespace std;

int addNumbers(int firstNum, int secondNum, int thirdNum)
{
  return firstNum + secondNum + thirdNum;
}

int getFactorial(int number)
{
  int sum;
  if(number == 1) sum = 1;
  else sum = getFactorial(number -1) * number;
  return sum;

//getFactorial(2) [Return 2] * 3;
//getFactorial(1) [Return 1} * 2;

}
  
int main()
{
  //cout << addNumbers(1) << endl;
  cout << addNumbers(1, 5, 6) << endl;
  cout << "Please enter a number to calculate factorial: ";
  int num = {0};
  cin >> num;
  cout << "The factorial of " << num << " is " << getFactorial(num) << endl;

}
