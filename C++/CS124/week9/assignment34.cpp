/***********************************************************************
* Program:
*    Assignment 34, Pointer Arithmetic
*    Brother Wagstaff, CS124
* Author:
*    Elbert Prescott
* Summary:
*    This program will identify frequent appearance of a letter in a  
*    sentence string or a word
*
*    Estimated:  2.0 hrs
*    Actual:     4.0 hrs
*    trying to figure out why the counting loop was not counting enough
*    letter for the 3rd testbed test took me a long time to figure out
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
 * countLetters() will count the frequency of a letter in a sentence
 **********************************************************************/
int countLetters(char * text, char letter)
{
   int count = 0;
   for (int i = 0; i < 45 && text[i] != '\0'; i++)
   {
      if (text[i] == letter)
         count++;
   }

   return count;
}

/**********************************************************************
 * MAIN
 * The main will prompt for letter and the string then call countLetter()
 * to count the amount of characters in a string
 ***********************************************************************/
int main()
{
   char letter;
   char text[256] = {};

   cout << "Enter a letter: ";
   cin >> letter;

   cout << "Enter text: ";
   cin.ignore();
   cin.getline(text,256);

   int count = countLetters(text, letter);
   cout << "Normal Way: Number of " << "'" << letter << "'s: " << count << endl;

   char *ptext = text;
   int pcount = countLetters(ptext, letter);
   cout << "Pointer Way: Number of " << "'" << letter << "'s: " << pcount << endl;
}
