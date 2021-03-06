#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
  //String of Text to be inserted to stevequote.txt
 
  string steveQuote = "Be brief be articulate and be gone!!";

  //Declare the ofstream variable
  ofstream writer("elbertquote.txt");

  //If statement if file cannot be opened
  if(! writer)
    {

      cout << "Error opening file" << endl;
      return -1;
    }

  //Else statement to write the string(steveQuote) to ofstream(writer)
  else
    {
      writer << steveQuote << endl;

  //Close the offstream once write is completed
      writer.close();
    }

  //New offstream for appending a new string
  ofstream writer2("elbertquote.txt", ios::app);

  //Open a stream to append to whats there using ios::app
  //ios::binary : treat the file as binary
  //ios::in : open a file to read input
  //ios::trunc : default
  //ios::out : open a file to write output


  if(! writer2)
    {

      cout << "Error opening file" << endl;
      return -1;
    }
  else
    {
      writer2 << "\n -Elbert Prescott" << endl;

      writer2.close();
    }


  //Outputting or printing out the stevequote.txt
  char letter;

  ifstream reader("elbertquote.txt");

  if(! reader){
    cout << "Error opening file" << endl;
    return -1;

  }
  else
    {
      for(int i = 0; ! reader.eof(); i++)
	{
	  reader.get(letter);
	  cout << letter;
	}

      cout << endl;
      reader.close();
    }

}
