/***********************************************************************
* Program:
*    Project 12, Sudoku
*    Brother Wagstaff, CS124
* Author:
*    Elbert Prescott
* Summary:
*    This project will display sudoku board
*
*    Estimated:  4.0 hrs
*    Actual:     12.0 hrs
*      A lot of issues with getting the formatting to testBed's liking
*      and a problem with one array that caused a segmentation fault
*      when I went out of its bounds. Also trying to get the formatting
*      right on the show options.
************************************************************************/

#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

const int SIZE = 9;

/***********************************************************************
 * Just getting the board name from the user.
 ************************************************************************/
bool checkBoard(int boardArray[][SIZE])
{
   int row = 0;
   int col = 0;
   char coords[2];

   for (int loop = 0; loop < SIZE; loop++)
   {
      int numCol[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      int numRow[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      int numBox[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      for (int irow = 0; irow < 9; irow++)
      {
         if (boardArray[irow][col] != 0)
            numCol[boardArray[irow][col]] += 1;
         if (numCol[boardArray[irow][col]] > 1)
         {
            coords[1] = irow + 48;
            coords[0] = col + 66;
            cout << "ERROR: Duplicate value '" << boardArray[irow][col]
                 << "' in inside square represented by '"
                 << coords[0] << coords[1] << "'\n";
            return false;
         }
      }
      for (int icol = 0; icol < 9; icol++)
      {
         if (boardArray[row][icol] != 0)
            numRow[boardArray[row][icol]] += 1;
         if (numRow[boardArray[row][icol]] > 1)
         {
            coords[1] = row + 48;
            coords[0] = icol + 66;
            cout << "ERROR: Duplicate value '" << boardArray[row][icol]
                 << "' in inside square represented by '"
                 << coords[0] << coords[1] << "'\n";
            return false;
         }
      }
      int mRow = (row / 3) * 3;
      int mCol = (col / 3) * 3;
      for (int r = mRow; r < (mRow + 3); r++)
      {
         for (int c = mCol; c < (mCol + 3); c++)
         {
            if(boardArray[r][c] != 0)
               numBox[boardArray[r][c]] += 1;
            if (numBox[boardArray[r][c]] > 1)
            {
               coords[1] = r + 48;
               coords[0] = c + 66;
               cout << "ERROR: Duplicate value '" << boardArray[r][c]
                    << "' in inside square represented by '"
                    << coords[0] << coords[1] << "'\n";
               return false;
            }
         }
      }
      row++;
      col++;
   }
   return true;
}

/***********************************************************************
 * Just getting the board name from the user.
 ************************************************************************/
void getBoard(char myBoard[])
{
   cout << "Where is your board located? ";
   cin.getline(myBoard, 256);
   return;
}

/***********************************************************************
 * Transfers data from the file into an array.
 ************************************************************************/
bool createArray(int boardArray[][SIZE], char myBoard[],
                 bool boardArrayRO[][SIZE])
{
   bool validBoard = true;
   ifstream fin(myBoard);
   if (fin.fail())
   {
      cout << "Unable to open file " << myBoard << ".\n";
      return true;
   }
   // First loop parsing the rows.
   for (int row = 0; row < SIZE; row++)
   {
      // For each row we go through the columns inputting info
      // from the file to our array.
      for (int col = 0; col < SIZE; col++)
      {
         fin >> boardArray[row][col];
         if (boardArray[row][col] != 0)
            boardArrayRO[row][col] = true;
         else
            boardArrayRO[row][col] = false;
      }
   }
   fin.close();
   validBoard = checkBoard(boardArray);
   if (!validBoard)
      return true;
   return false;
}

/***********************************************************************
 * Stores arrays and calls other functions
 ************************************************************************/
void drawBoard(int boardArray[][SIZE], bool boardArrayRO[][SIZE])
{
   cout << "   A B C D E F G H I\n";
   // First loop parsing the rows
   for (int row = 0; row < SIZE; row++)
   {
      cout << row + 1 << "  ";
      // For each row we go through the columns inputting info
      // from the array onto the screen matching the desired format.
      for (int col = 0; col < SIZE; col++)
      {
         // If the array value is 0 we want a blank space instead.
         if (boardArray[row][col] == 0)
            cout << " ";
         else
         {
            if (boardArrayRO[row][col])
               cout << boardArray[row][col];
            else
               cout << boardArray[row][col];
         }
         // Put a space between the columns except for the
         // the columns 3, 6, and 9.
         if ((col + 1) % 3 != 0)
            cout << " ";
         // The last column gets a new line.
         else if (col == (SIZE - 1))
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

/***********************************************************************
 * displayMenu() display the options menu
 ************************************************************************/
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

/***********************************************************************
 * interact() handles the interactions from the user, calling the 
 * appropriate function depending on the users input.
 ************************************************************************/
void interact(int boardArray[][SIZE], bool boardArrayRO[][SIZE])
{
  char userInput;
  bool stayInLoop = true;
  displayMenu();
  drawBoard(boardArray,boardArrayRO);
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
	   	     drawBoard(boardArray,boardArrayRO);
	     break;/*
	   case 'E':
	   case 'e':
	     editArray(boardArray,boardArrayRO);
	     break;
	   case 'S':
	   case 's':
	     showOptions(boardArray,boardArrayRO);
	     break;
	   case 'Q':
	   case 'q':
	     stayInLoop = saveAndQuit(boardArray);
	     break;
	   default:
	   cout << "ERROR: Invalid command\n\n"; */
	   }
       }
     while (stayInLoop);
     return;
}

/***********************************************************************
* main() stores arrays and calls other functions
************************************************************************/
int main()
{
   char myBoard[256];
   int boardArray[SIZE][SIZE];
   bool boardArrayRO[SIZE][SIZE];
   getBoard(myBoard);

   if (createArray(boardArray,myBoard,boardArrayRO))
     return 0;
   interact(boardArray,boardArrayRO);
   return 0;
}
