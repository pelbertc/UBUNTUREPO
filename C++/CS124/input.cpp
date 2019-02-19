#include <iostream>
#include <fstream>
using namespace std;

/******************************************************************
 * This function will use the EOF method. Not that it will 
 * behave incorrectly when there is a white space immediately
 * before the EOF character in the file
 *****************************************************************/
void usingEOF(const char fileName[])
{
  //open
  ifstream fin(fileName);
  if(fin.fail())
    {
      cout << "Unable to open file" << 'FileName' <<  endl;
      return;
    }

  //get the data and display it on the screen
  char text[256];
  
  //keep reading as long as I am not at the end of the file
  while(!fin.eof())
    {
      //not that if this fails to read anything(such as when there
      //is nothing bug a white space between the file pointer and the
      //end of the file), then txt will keep same value as the
      //previous excution of the loop
      fin >> text;
      
	cout << "'" << text << "' ";
    }
    
  //close
  fin.close();
  
}

/******************************************************************
 * This function will not use the EOF method. This function will
 * corrrectly handle both the condition where there is a valid data
 * immediately before the EOF and when there is a white space before the
 * EOF
 *****************************************************************/
void notUsingEOF(const char fileName[])
{
  //open
  ifstream fin(fileName);
  if(fin.fail())
    {
      cout << "Unable to open file" << 'FileName' <<  endl;
      return;
    }

  //get the data and display it on the screen
  char text[256];
  // keep reading as long as
  // 1. Not at the end of the file
  // 2. Did not fail to read the text into our variable
  // 3. There nothing else wrong with the file
  while(fin >> text)
    {
	cout << "'" << text << "' ";
    }

  //close
  fin.close();

}

int main()
{
  //fileName reading
  char fileName[256];
  cout << "Filename? ";
  cin >> fileName;

  //chose between the two methods
  cout << "Use the EOF method? (y/n) ";
  char response;
  cin >> response;
  
  //execute
  if(response == 'y' || response == 'Y')
    usingEOF(fileName);
  else
    notUsingEOF(fileName);
  
  return 0;
}
