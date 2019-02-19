/***********************************************************************
 * Program:
 *    Assignment 26, Files
 *    Brother Wagstaff, CS124
 * Author:
 *    Elbert Prescott
 * Summary:
 *    this program will read a text file with multiple grades then generate
 *    average grade
 *
 *    Estimated:  2.0 hrs
 *    Actual:     4.0 hrs
 *    figuring out how to read file and calculate it average took me hours
 ************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
 * getFileName() will input the file name to be read
 ***********************************************************************/
void getFileName(char fileName[])
{
  cout << "Please enter the filename: ";
  cin >> fileName;
}

/**********************************************************************
 * readFile() will read the text file and compute the average grade
 ***********************************************************************/
float readFile(char fileName[])
{
  //open the data
  ifstream fin(fileName);
  if (fin.fail())
    return 0.0;

  //read the data
  float average;
  char grade[10];
  float sum;

  while(fin >> grade)
    sum += grade;
  average = sum/10;

  //close and return the data
  fin.close();
  return average;
}

/**********************************************************************
 * display() will display the average grade
 ***********************************************************************/
void display(float value)
{
  cout.setf(ios::fixed);
  cout.precision(0);
  cout << "Average Grade: " << value << '%' << endl;
}

/**********************************************************************
 * MAIN
 * The main will call the 3 funtions to input the file name, generate
 * then display average
 ***********************************************************************/
int main()
{
  char file[256] = {0};
  getFileName(file);
  float average = readFile(file);
  display(average);

  return 0;
}
