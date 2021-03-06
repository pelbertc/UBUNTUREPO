/***********************************************************************
 * Program:
 *    Project 08, MAD LIB
 *    Brother Wagstaff, CS124
 * Author:
 *    Elbert Prescott
 * Summary:
 *    The program will prompt the user for the file that describes the
 *    Mad Lib®, and then prompt him for all the substitute words. When
 *    all the prompts are complete, the program will display the
 *     completed story on the screen.
 *
 *    Estimated:  15.0 hrs
 *    Actual:     20.0 hrs
 *    still in planning phase
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void readFile(const char filename[])
{
   cout << "not using eof" << endl;

   //open file
   ifstream fin(filename);
   if(fin.fail())
   {
      cout << "Unable to open file" << filename << endl;
      return;
   }

   char text[256];
   int count = 0;
   int numWords = 0;
   
   //keep reading as long as:
   // 1. Not at the end of a file
   // 2. did not fail to read into our variable
   // 3. There is nothing else wrong with the file
   
   while (numWords < 256 && fin >> text)
   {
     if(filename[numWords < 256 &&      
      cout << text << " ";

   }
   cout << endl;

   //done
   fin.close();

}

void askQuestion(const char filename[])
{
   cout << "not using eof" << endl;

   //open file
   ifstream fin(filename);
   if(fin.fail())
   {
      cout << "Unable to open file" << filename << endl;
      return;
   }

   char text[256];
   //keep reading as long as:
   // 1. Not at the end of a file
   // 2. did not fail to read into our variable
   // 3. There is nothing else wrong with the file
   int countp = {0};
   
   while (fin >> text)
   {
      for(int i = 0; text[i]; i++)
      {
         if(text[i] == ':')
	   cout << text << '\n' ;
      }
      countp++;
   }
   
   cout << countp << endl;
   
   cout << endl;

   //done
   fin.close();

}

int main()
{
   char fileName[256];
   cout << "Please enter filename: ";
   cin >> fileName;
   readFile(fileName);
   askQuestion(fileName);
   
   return 0;

}
