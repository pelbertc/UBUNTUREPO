/***********************************************************************
* Program:
*    Project 10, MAD LIB PROGRAM
*    Brother Wagstaff, CS124
* Author:
*    Elbert Prescott
* Summary:
*    The program will prompt the user for the file that describes the
*    Mad Lib, and then will pick keyword starts with token : and prompt
*    for substitute words. 
*     
*
*    Estimated:  15.0 hrs
*    Actual:     20.0 hrs
*    passing value from readfile() to askquestions() was the hardest
*    took a little while to figure out which variables and I need to
*    pass and how to display these key words in question format
************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;

void getFile(char fileName[]);
int readFile(char allTheWords[][32]);
void askQuestions(char prompt[], int count);
void getPunctuation(char isPunc[]);
void display (char allTheWords[][32], int numWords);

/**********************************************************************
 * This function will prompt the user for the name of the file
 ***********************************************************************/
void getFile(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   //filename will be stored under fileName array
   cin >> fileName;

   return;
}

/**********************************************************************
 * This function will read the file that the user input
 ***********************************************************************/
int readFile(char allTheWords[][32])
{
   //declaring fileName array
   char fileName[256];
   getFile(fileName);
   ifstream file(fileName);
   //the condition that will show an error text if cant find the file
   if (file.fail())
   {
      //return error message if file cannot be read
      cout << "Error reading file: " << fileName << endl;
      return 0;
   }
   
   //number of words must be less than 256 words
   int count = 0;
   int numWords = 0;
   //while reading every word to multi-dimensional array madLibText 
   while (numWords < 256 && file >> allTheWords[numWords])
   {
      //loop for : and the next character is a letter
      if (allTheWords[numWords][0] == ':' && isalpha(allTheWords[numWords][1]))
      {
         //pass these words to askQuestions() with the count of these numbers
         askQuestions(allTheWords[numWords], count);
         count++;
      }
      //else if(allTheWords[numWords][0] == ':' && !isalpha(allTheWords[numWords][2]))
      //   getPunctuation(allTheWords[numWords]);
         numWords++;
   }

   file.close();
   return numWords;
}

/**********************************************************************
 * This function will ask for words to be substituted in the
 * allTheWords[] then will pass these values back to readFile()
 ***********************************************************************/
void askQuestions(char text[], int count)
{
   cout << "\t" << (char)toupper(text[1]);

   for (int i = 2; text[i]; i++)
   {
      if (text[i] == '_')
         cout << " ";
      else
      {
         cout << (char)tolower(text[i]);
      }
   }

   cout << ": ";

   if (count == 0)
   {
      cin.ignore();
      cin.getline(text,256);
   }
   else if (count > 0)
      cin.getline(text,256);

   return;
}

/**********************************************************************
 * This function will use advanced conditionals to make the program work properly
 ***********************************************************************/
void getPunctuation(char isPunc[])
{ 
      switch (isPunc[1])
      {
//         case '!':
         //           isPunc[1] = '\n';
         //  break;

//         case '.':
//            isPunc[1] = '.';
//            break;
	//        case ',':
	//   isPunc[1] = ',';
      }
  
  

   return;
}

/**********************************************************************
 * This function will display the program output
 ***********************************************************************/
void display (char allTheWords[][32], int numWords)
{
  cout << "\n";

  bool needASpace = false;
  
  for (int i = 0; i < numWords; i++)
    {
      if(allTheWords[i][0] == ':')
	{
	  if(allTheWords[i][1] == ',')
	  {
            cout << ",";
	    needASpace = true;
	  }
	  if(allTheWords[i][1] == '.')
	  {
	    cout << ".";
	    needASpace = true;
	  }
	  if(allTheWords[i][1] == '<')
	  {
	    if(needASpace)
	      cout << " ";
	    cout << "\"";
	    needASpace = false;
	  }
	  if(allTheWords[i][1] == '>')
	  {
	    cout << "\"";
	    needASpace = true;
	  }
	  if(allTheWords[i][1] == '!')
	  {
	    cout << "\n";
	    needASpace = false;
	  }
    
	  /*     
	}
        else if (allTheWords[i][0] == ':' || allTheWords[i][1] == ',')
        {
          cout << allTheWords[i][1];
	}
         else  if ((allTheWords[i][0] == '!') && isalpha(allTheWords[i+1][0]))
	{
	  cout << '\n';
	}
	  */}
      else
	{
	  if(needASpace)
	    cout << " ";
	  needASpace = true;
	  cout << allTheWords[i];
	}
    }

   return;
}

/**********************************************************************
 * The main function will call the readFile() to read madlib text
 * and process these text, then say thank you for playing. 
 ***********************************************************************/
int main()
{
   char allTheWords[256][32];
   int numWords;

   numWords = readFile(allTheWords);
   display (allTheWords, numWords);
   cout << endl; 
}
