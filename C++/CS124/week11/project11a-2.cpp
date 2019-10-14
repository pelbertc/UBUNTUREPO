#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
bool row(int s,int o,int n);
bool column(int s,int o,int n);
bool square(int s,int o,int n);

/**********************************************************************
 * This function will display the program output
 ***********************************************************************/
bool row(int sudokuGrid[][9],int s,int o,int n)
{
   for (int g = 0; g < 9; g++)
   {

      if (sudokuGrid[s][g] == n)
      {
         return 0;
      }
   }
   return 1;
}

/**********************************************************************
 * This function will display the program output
 ***********************************************************************/
bool column(int sudokuGrid[][9],int s,int o,int n)
{
   for (int g = 0; g < 9; g++)
   {
      if (sudokuGrid[g][o] == n)
         return 0;
   }
   return 1;
}

/**********************************************************************
 * This function will display the program output
 ***********************************************************************/
bool square(int sudokuGrid[][9],int s,int o,int n)
{
   int row = ceil( (s+1) / 3.);
   int column = ceil( (o+1) / 3.);
   for(int g = (row-1) * 3; g < ((row-1) * 3+3); g++)
      for(int h = (column-1) * 3; h < ((column-1) * 3+3); h++)
      {
         if(sudokuGrid[g][h] == n)
            return 0;
      }
   return 1;
}

/**********************************************************************
 * This function will display the program output
 ***********************************************************************/
void getFilename(char fileName[])
{
	cout << "Give the sudoku filename: ";
	cin >> fileName;
	
}

/**********************************************************************
 * This function will display the program output
 ***********************************************************************/
int readFile(int sudokuGrid [][9], int space)
{
  //declaring fileName array
  char fileName[256];
  getFilename(fileName);
  ifstream in(fileName);
  for(int i = 0; i < 9; i++)
    {
      for(int j = 0; j < 9; j++)
	{
	  in >> sudokuGrid[i][j];
	  if(!sudokuGrid[i][j])
	    space++;
	}
    }
  in.close();
  

}

/**********************************************************************
 * This function will display the program output
***********************************************************************/
void displayMenu()
{
  cout << "Options:\n"
       << "   ?  Show these instructions\n"
       << "   D  Display the board\n"
       << "   E  Edit one square\n"
       << "   S  Show the possible values for a square\n"
       << "   Q  Save and Quit\n\n";
  return;
}

/**********************************************************************
 * This function will display the program output
 ***********************************************************************/
void display(int sudokuGrid[][9])

{
  displayMenu();

  for (int i = 0; i < 9; i++)
{
   for (int j = 0; j < 9; j++)
   {
      cout << sudokuGrid[i][j] << " ";
   }
   
   cout << endl;
}
cout << endl;

}

/**********************************************************************
 * This function will display the program output
 ***********************************************************************/
void interact(int sudokuGrid[][9])
{
  int space = 0;
  readFile(sudokuGrid, space);
  display(sudokuGrid);
  char userInput;
  bool inputLoop = true;
  //displayMenu();
  //display(sudokuGrid);
       do
	 {
	   cout << "> ";
	   cin >> userInput;
	   switch (userInput)
	     {
	     case '?':
	       displayMenu();
	       cout << endl;
	       break;
	     case 'D':
	     case 'd':
	       display(sudokuGrid);
	       break;
	     }
	 }
       while (inputLoop);
       return;
}

/**********************************************************************
 * This function will display the program output
 ***********************************************************************/
int main()
{
   int sudokuGrid[9][9];
   char file[20];
  
   interact(sudokuGrid);

}   



