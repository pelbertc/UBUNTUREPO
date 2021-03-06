#include <iostream>
#include <fstream>
using namespace std;

/**************************************/
void usingEOF(const char filename[])
{
  cout << "using eof" << endl;
  
  //open file
  ifstream fin(filename);
  if(fin.fail())
    {
      cout << "Unable to open file" << filename << endl;
      return;
    }

  char text[256];

  //read file as long as 1. not at the end of a line
  while (!fin.eof())
    {
      fin >> text;
      cout << "'" << text << "'";

    }
      cout << endl;

  //done
  fin.close();
}

/***********most correct solution***********/
void notUsingEOF(const char filename[])
{
    cout << "using eof" << endl;

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
    int count;
    while (fin >> text)
      {
	++count;
	cout << count << ". " << text << "\n";

      }
    cout << endl;

    //done
    fin.close();
 
}

/*****************************************/
int main()
{
  
  //filename reading
  char fileName[256];
  cout << "Filename: ";
  cin >> fileName;

  
  //choose between the 2 methods
  cout << "Use the EOF metho?(y/n) ";
  char response;
  cin >> response;

  
  //execute
  if(response == 'y' || response == 'Y')
    usingEOF(fileName);
  else
    notUsingEOF(fileName);
}
