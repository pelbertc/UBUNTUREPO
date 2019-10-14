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
  ifstream cin(fileName);
  for(int i = 0; i < 9; i++)
    {
      for(int j = 0; j < 9; j++)
	{
	  cin >> sudokuGrid[i][j];
	  if(!sudokuGrid[i][j])
	    space++;
	}
    }
  cin.close();
}

/**********************************************************************
 * This function will display the program output
 ***********************************************************************/
void edit(int sudokuGrid[][9])
{
  bool values[10];
  char coords[2];
  int inputNum;
  int col;
  int row;
  if (getCoords(coords,sudokuGrid))
    {
      // Convert the user input to corresponding values of array.
      col = coords[0] - 65;
      row = coords[1] - 49;
      // Get new number from the user.
      inputNum = promptNum(coords);
      if (inputNum != 0)
	{
	  // Make sure the number is available for use
	  getValues(sudokuGrid,coords,values);
	  if (values[inputNum])
	    {
	      sudokuGrid[row][col] = inputNum;
	      cout << endl;
	      return;
	    }
	  else
	    {
	      cout << "ERROR: Value '" << inputNum
		   << "' in square '" << coords[0] << coords[1]
		   << "' is invalid\n\n";
	      return;
	    }
	}
      else
	return;
    }
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
  cout << "   A B C D E F G H I\n";
  // first loop through the rows
  for (int row = 0; row < 9; row++)
    {
      cout << row + 1 << "  ";
      // for every row we go through we apply changes to columns 
      // inputting and displaying correct format of the sudokuGrid
      for (int col = 0; col < 9; col++)
	{
	  //replacing the 0 on the sudokudu file with space.
	  if (sudokuGrid[row][col] == 0)
	    cout << " ";
	  else
	    {
		cout << sudokuGrid[row][col];
	    }
	  // putting columns on some of these columns
	  // the columns 3, 6, and 9.
	  if ((col + 1) % 3 != 0)
	    cout << " ";
	  // putting new line on the last quorum
	  else if (col == (9 - 1))
	    cout << endl;
	  // The 3rd and 6th columns get pipe symbol.
	  else
	    cout << '|';
	}
      // 3rd and 6th rows get spacers after them.
      if (row == 2 || row == 5)
	cout << "   -----+-----+-----\n";
    }
  cout << "\n";
}

/**********************************************************************
 * This function will display the program output
 ***********************************************************************/
void interact(int sudokuGrid[][9])
{
  int space = 0;
  readFile(sudokuGrid, space);
  displayMenu();
  display(sudokuGrid);
  char userInput;
  bool inputLoop = true;
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
	     case 'E':
	     case 'e':
	       edit(sudokuGrid);
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



