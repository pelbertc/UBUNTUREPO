#include <iostream>
#include <fstream>
using namespace std;
void getFileName(char fileName[]);
int readFile(char madLibStory[][32]);
void askQuestions(char prompt[], int count);
void getPunctuation(char punc[]);
void display (char madLibStory[][32], int numWords);
/**********************************************************************                                                
 * Add text here to describe what the function "main" does. Also don't forget                                          
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.                                                      
 ***********************************************************************/
void getFileName(char fileName[])
{
  cout << "Please enter the filename of the Mad Lib: ";
  cin >> fileName;
}
/**********************************************************************                                                
 * Add text here to describe what the function "main" does. Also don't forget                                          
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.                                                      
 ***********************************************************************/
int readFile(char madLibStory[][32])
{
  char fileName[256];
  getFileName(fileName);
  ifstream fin(fileName);
  if (fin.fail())
    {
      cout << "Error reading file: " << fileName << endl;
      return -1;
    }
  int count = 0;
  int numWords = 0;
  while (numWords < 256 && fin >> madLibStory[numWords])
    {
      if (madLibStory[numWords][0] == '<' && isalpha(madLibStory[numWords][1]))
	{
	  askQuestions(madLibStory[numWords], count);
	  count++;
	}
      else if (madLibStory[numWords][0] == '<' && !isalpha(madLibStory[numWords][2]))
	getPunctuation(madLibStory[numWords]);
      numWords++;
    }
  fin.close();
  return numWords;
}
/**********************************************************************                            
 * Add text here to describe what the function "main" does. Also don't forget                      
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.                                  
 ***********************************************************************/
void askQuestions(char text[], int count)
{
  cout << "\t" << (char)toupper(text[1]);
  for (int i = 2; text[i] != '>'; i++)
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
 * Add text here to describe what the function "main" does. Also don't forget                      
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.                                  
 ***********************************************************************/
void getPunctuation(char punc[])
{
  switch (punc[1])
    {
    case '#':
      punc[0] = '\n';
      punc[1] = '\0';
      break;
    case '{':
      punc[0] = ' ';
      punc[1] = '\"';
      punc[2] = '\0';
      break;
    case '}':
      punc[0] = '\"';
      punc[1] = ' ';
      punc[2] = '\0';
      break;
    case '[':
      punc[0] = ' ';
      punc[1] = '\'';
      punc[2] = '\0';
      break;
    case ']':
      punc[0] = '\'';
      punc[1] = ' ';
      punc[2] = '\0';
      break;
    }
  return;
}
/**********************************************************************                            
 * Add text here to describe what the function "main" does. Also don't forget                      
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.                                  
 ***********************************************************************/
void display (char madLibStory[][32], int numWords)
{
  cout << "\n";
  for (int i = 0; i < numWords; i++)
    {
      if (madLibStory[i + 1][0] == '.' || madLibStory[i + 1][0] == ',' ||
	            madLibStory[i][0] == '\n'|| madLibStory[i + 1][0] == '!' || madLibStory[i + 1][0] == '?'
	            || madLibStory[i + 1][0] == '\"' || madLibStory[i + 1][0] == '\''
	            || madLibStory[i][0] == '<' || madLibStory[i + 2][0] == '#' ||  madLibStory[i][0] == '>'\
	  )
	cout << madLibStory[i];
      else
	cout << madLibStory[i] << ' ';
    }
  return;
}
/**********************************************************************                            
 * Add text here to describe what the function "main" does. Also don't forget                      
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.                                  
 ***********************************************************************/
int main()
{
  char madLibStory[256][32];
  int numWords;
  char yesOrNo;
  bool playAgain = true;
  while (playAgain)
    {
      numWords = readFile(madLibStory);
      display(madLibStory, numWords);
      cout << "\n";
      cout << "Do you want to play again (y/n)? ";
      cin >> yesOrNo;
      if (yesOrNo == 'n')
	{
	  playAgain = false;
	  cout << "Thank you for playing." << endl;
	}
      else if (yesOrNo == 'y')
	playAgain = true;
      else if (yesOrNo != 'y' || yesOrNo != 'n')
	{
	  cout << "Invalid entry. Do you want to play again (y/n)? ";
	  cin >> yesOrNo;
	}
    }
  return 0;
}
