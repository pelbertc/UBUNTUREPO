#include <iostream>
#include <assert.h>
using namespace std;

int main()
{
  int array[] = { 7,4,2,9,3,1,8,2,9,1,2};

  cout << "array[0] == " << array[0] << endl;
  cout << "*array == " << *array << endl;
  assert(array[0] = *array);

  cout << "array[5]  == " << array[5] << endl;
  cout << "*(array + 5) == " << *(array +5) << endl;
  assert(array[5] == *(array + 5));
}
