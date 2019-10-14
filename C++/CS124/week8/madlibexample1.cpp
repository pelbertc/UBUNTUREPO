/***********************************************************************
 * Program:
 *    Project 3, MadLib  
 *    Brother Burton, CS124
 * Author:
 *    Hunter Marshall
 * Summary: 
 *    This program will prompt the user for a file that describes the
 *    Mad Lib, and then prompt him for all the substitute words. When   
 *    all the prompts are complete, the program will display the 
 *    completed story on the screen.
 *
 *
 *    Estimated:  4.0 hrs   
 *    Actual:     8.0 hrs
 *      Figuring out the spacing was the hardest part.
 ************************************************************************/

#include <iostream>
#include <fstream>

using namespace std;


/**********************************************************************
 * Function askQuestions
 * This function prompts the users for the input for the Mad Lib game.
 ***********************************************************************/
void askQuestions(char text[])
{
  // Check to see if the text starts with the char '<' and if it doesn't
  // return back to the function readFile
  if (text[0] != '<' || !isalpha(text[1]))
    return;

  // Make the first letter of every question upper case
  cout << "\t" <<  (char)toupper(text[1]);

  // Make the questions more easy to read.'>' tells the loop when to stop
  for (int iText = 2; text[iText] != '>'; iText++)
    {
      // Make all char '_'s into a space.
      if (text[iText] == '_')
	{
	  cout << " ";
	}
      // Or else display the text and make sure it is lower case
      else
	{
	  // Make all text lower case
	  cout << (char)tolower(text[iText]);;
	}
    }

  // Display a ':' and a space and then get the user's input
  cout << ": ";

  cin.getline(text, 256);
}

/**********************************************************************
 * Function getFileName
 * This function prompts the user for the file name of the Mad Lib.
 ***********************************************************************/
void getFileName(char fileName[])
{
  // Get the file name of the Mad Lib game from the user.
  cout << "Please enter the filename of the Mad Lib: ";
  cin >> fileName;
  cin.ignore(256, '\n');
}

/**********************************************************************
 * Function readFile
 * This function calls the getFileName function, reads the file, calls
 * the function askQuestions, adds up the number of words, and then
 * returns the number of words to main.
 ***********************************************************************/
int readFile(char story[][32])
{
  // Get the file name
  char fileName[256];
  getFileName(fileName);
  ifstream fin(fileName);
  // Check the fail and if it fails return error message
  if (fin.fail())
    {
      cout << "Unable to open: " << fileName << endl;
      return 0;
    }

  // Call the function askQuestions to determine the user input and
  // also adds up the number of words.
  int numWords = 0;
  while (numWords < 256 && fin >> story[numWords])
    {
      askQuestions(story[numWords]);
      numWords++;

    }

  cout << endl;

  // Close and return the data
  fin.close();
  return numWords;
}

/**********************************************************************
 * Function isPunc
 * This function determines what the cheracter means.
 ***********************************************************************/
void isPunc(char character[], char char2[])
{
  // Deteremines what the character means.
  // if character is a pound sign then end line
  if (character[1] == '#')
    {
      cout << endl;
    }
  // if character is open curly brace display space and then open quote
  else if (character[1] == '{')
    {
      cout << " \"";
    }
  // if character is clsoed curly brace  then display closed quote and space
  else if (character[1] == '}')
    {
      // if closed curly brace follows a letter then display closed quote
      // and then space or else just display the closed quote
      if (character[1] == '}' && isalpha(char2[0]))
	{
	  cout << "\" ";
	}
      else
	cout << "\"";
    }
  // if character is [ then display space and then open single quote
  else if (character[1] == '[')
    {
      cout << " '";
    }
  // if character is ] then display closed single quote and then space
  else if (character[1] == ']')
    {
      cout << "' ";
    }
}

/**********************************************************************
 * Function needSpace
 * This function helps determine where the spaces needed.
 ***********************************************************************/
void needSpace(char first[], char second[])
{
  // Determine where a space is needed
  if (isalpha(first[0]) && isalpha(second[0]))
    {
      cout << " ";
    }
  else if (first[0] == '.' && isalpha(second[0]))
    {
      cout << " ";
    }
  else if (first[0] == ',' && isalpha(second[0]))
    {
      cout << " ";
    }
}

/**********************************************************************
 * Function displayStory
 * This function calls the isPunc function and also displays the story
 ***********************************************************************/
void displayStory(char story[][32], int length)
{
  // Display the story
  int numOfWords = 0;
  for (numOfWords = 0; numOfWords < length; )
    {
      // if character is < call isPunc function
      if (story[numOfWords][0] == '<')
	{
	  // Call isPunc function to detemine what the characters mean
	  // in the file called by the user.
	  isPunc(story[numOfWords], story[numOfWords + 1]);
	}
      else
	{
	  cout << story[numOfWords];
	}

      // Determine the spacing of the characters in the needSpace function
      needSpace(story[numOfWords], story[numOfWords + 1]);

      // add 1 to numOfWords
      numOfWords++;

    }

  // new line
  cout << endl;
}

/**********************************************************************
 * Function playAgain
 * Asks the user if they want to play again.
 ***********************************************************************/
void playAgain(char &contGame)
{
  // Ask the user if they want to play again
  cout << "Do you want to play again (y/n)? ";
  cin >> contGame;

}

/**********************************************************************
 * MAIN
 * This function calls the readFile function, the display function, and
 * the playAgain function. Then it detemines if the user is wanting to
 * play again or not. If it does it calls the functions again. 
 ***********************************************************************/
int main()
{
  char story[256][32];

  // call the readFile function to get the file name and read the file
  int length = readFile(story);

  // display the story onto the screen
  displayStory(story, length);

  // call the playAgain function to prompt the user if they want to
  // play again. If they do then call the functions again
  char contGame;
  playAgain(contGame);
  while (tolower(contGame) == 'y')
    {
      length = readFile(story);
      displayStory(story, length);
      playAgain(contGame);
    }

  // Display thank you message once the user is done playing.
  cout << "Thank you for playing.\n";

  return 0;
}
