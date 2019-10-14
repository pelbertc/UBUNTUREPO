#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

/***********************************
*READ FILE
*Read the data from file. Make sure
*there is no more data in file than
*we have room in our array!
***********************************/
int readFile(const char fileName[], int data[], int max)
{
  //open the file for reading
  ifstream fin(fileName);
  if(fin.fail())
    {
      cout << "ERROR: Unable to read file " << fileName << endl;
      return 0; //unable to read any item at all
    }
  
  //loop through the file, reading the elements on at a time
  int numRead = 0; //initially non were read
  while(numRead < max && fin >> data[numRead])
	numRead++;
	//the above code is the same as:
	//while(numRead < max && !fin.eof())
	// fin >> data[numRead++];
	//one different .. what if the fin >> data[numRead] failed!
      
  //close the file and return
  fin.close();
  return numRead;
}
/***************************************
*DISPLAY
*Display all the data read from file
**************************************/
void display(const int data[], int num)
{
  //standard for loop
  for(int i = 0; i < num; i++)
    cout << "\t" << data[i] << endl;

}

int main()
{
  //fetch the filename
  char fileName[256];
  cout << "Please enter filename: ";
  cin >> fileName;

  //read the data from the file
  int data[MAX];
  int numRead = readFile(fileName, data, MAX);
  
  //display the results
  display(data, numRead);

  return 0;
}
