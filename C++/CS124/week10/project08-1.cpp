#include <iostream>
#include <fstream>
using namespace std;

void getFile(char fileName[]);
int readFile(char madLibText[][32]);
void askQuestions(char prompt[], int count);
void getPunctuation(char isPunc[]);
void display (char madLibText[][32], int numWords);
bool playAgain = true;

/**********************************************************************
 * This function will prompt the user for the name of the file
 ***********************************************************************/
void getFile(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   // File will be stored under fileName
   cin >> fileName;

   return;
}

/**********************************************************************
 * This function will read the file that the user typed
 ***********************************************************************/
int readFile(char madLibText[][32])
{
   // Declaring functions
   char fileName[256];
   getFile(fileName);
   ifstream file(fileName);

   // The condition that will show an error text if there is an error with the file
   if (file.fail())
   {
      // Return error message if file cannot be read
      cout << "Error reading file: " << fileName << endl;
      return 0;
   }
   
   // Must be less than 256 words
   int count = 0;
   int numWords = 0;
   while (numWords < 256 && file >> madLibText[numWords])
   {
      if (madLibText[numWords][0] == ':' && isalpha(madLibText[numWords][1]))
      {
         askQuestions(madLibText[numWords], count);
         count++;
      }
      else if(madLibText[numWords][0] == ':' && !isalpha(madLibText[numWords][2]))
	    
	    getPunctuation(madLibText[numWords]);
         numWords++;
	 
      //cout << "NumWords: " << numWords << endl; 

   }

   file.close();
   return numWords;
}

/**********************************************************************
 * This function will ask for the questions in the program
 ***********************************************************************/

// The function askQuestions will read the text entered by the user, and will read the questions and record the answers.
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
  {
    switch (isPunc[1])
      {
      case '!':
	isPunc[1] = '\n';
	break;
      case '<':
	isPunc[1] = '\"';
      case '>':
	isPunc[1] = '\"';
      case '.':
	isPunc[1] = '.';
      case ',':
	isPunc[1] = ',';
      }

  }
   return;
}


/**********************************************************************
 * This function will display the program output
 ***********************************************************************/
void display (char madLibText[][32], int numWords)
{
   for (int i = 0; i < numWords; i++)
   {
     switch (madLibText[numWords][1])
       {
       case ':':
	 (madLibText[numWords][1]) = ' ';
	  
	  default:
         cout << madLibText[i];
       }
   }

   return;
}

/**********************************************************************
 * The main function will call the other functions
 * and will make the program work
 ***********************************************************************/
int main()
{
   char madLibText[256][32];
   int numWords;

   // Followed Instructions to write a while loop to play any number of games
   while (playAgain)
   {
      numWords = readFile(madLibText);
      display (madLibText, numWords);
      char YN;
      cout << "Do you want to play again (y/n)? ";
      cin >> YN;
      {
         // If user responds n, the game is over
         if (YN == 'n')
         {
            playAgain = false;
            cout << "Thank you for playing." << endl;
         }
         // If user responds y, the loop will start the game again
         else if (YN == 'y')
         {
            playAgain = true;
            numWords = readFile(madLibText);
         }
      }
   }
}







