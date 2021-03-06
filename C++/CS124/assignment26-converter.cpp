/**********************************************************************
* Program:
*    Assignment 26, Files
*    Brother Wagstaff, CS124
* Author:
*    Elbert Prescott
* Summary:
*    this program will read a text file with multiple grades then generate
*    average grade
*
*    Estimated:  4.0 hrs
*    Actual:     8.0 hrs
*    figuring out how to read through the whole file and be able to
*    calculate all its values inside was difficult and time consuming
*    trying to grasp these new concepts takes times especially with
*    ifstream etc.
************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
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
   {
      cout << "Error reading file \"" << fileName << "\"" << endl;
      exit(0);

   }
   else 
   {
      //read the data
      float grade = {0};
      float sum = {0};
      float tbvalue = {0};
      int itemRead = 0;
   
      while (fin >> grade)
      {
         sum += grade;
         ++itemRead;
      } 

      if (itemRead < 1 || itemRead > 2000)
      {
         cout << "Error reading file \"" << fileName << "\"\n"; 
         exit(0);
      }
      else
      {
         tbvalue = sum / 1024 / 1024 / 1024;
      
       //close and return the data
         fin.close();
         return tbvalue;
      } 
   }
}

/**********************************************************************
 * display() will display the average grade
 ***********************************************************************/
void display(float value)
{
   cout.setf(ios::fixed);
   cout.precision(2);
   cout << "Total Size of Data: " << value << " TB" << endl;
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
   float total = readFile(file);
   display(total);

   return 0;
}
