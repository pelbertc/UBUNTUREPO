/***********************************************************************
* Program:
*    Project 12, Sudoku
*    Brother Comeau, CS124
* Author:
*    Kwok Moon, Ho
* Summary:
*    Write a program for the second part of Sudoku.
*
*    Estimated:  4.0 hrs
*    Actual:     8.0 hrs
*      Please describe briefly what was the most difficult part.
*      Remembering the code is really difficult.
************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <string>
#include <cctype>
#include <stdio.h>
#include <ctype.h>
#include <sstream>

using namespace std;
int main();
void displayboard(int board[][9]);
void writeFile(int sudokuBoard[][9]);
void displayoptions();
void getFile(int board[][9]);
void getCoordinates(int &r, char &c);
void editSquare(int board[][9],int r, char c);
bool computePossible(int x, int y,int board[][9],int value);
void displayPossible(int board[][9], int r, int c );
bool computeValues(int r, int c,int board[][9],int value);

/**********************************************************************
 * getFile
 ***********************************************************************/
void getFile(int board[][9])
{
   char filename[256];
   ifstream fin;
   cout << "Where is your board located? ";
   cin  >> filename;
   fin.open(filename);
   if (fin.fail())
   {
      cout << "Input file opening failed.\n";
      return;
        
   }
   for (int c = 0; c < 9; c++)
   {
      for (int r = 0; r < 9; r++)
      {
         fin >> board[r][c];
      }
   }
   fin.close();
   return;
}

/**********************************************************************
 * displayoption
 ***********************************************************************/
void displayoptions()
{
   cout << "Options:\n"
        << "   ?  Show these instructions\n"
        << "   D  Display the board\n"
        << "   E  Edit one square\n"
        << "   S  Show the possible values for a square\n"
        << "   Q  Save and Quit\n"
        << "\n";
}

/**********************************************************************
 * displayboard
 ***********************************************************************/
void displayboard(int board[][9])
{
   cout << "   A B C D E F G H I\n";
   for (int r = 0; r < 9; r++)
   {
      cout << r + 1 << "  ";
      for (int c = 0; c < 9; c++)
      {
         if (board[c][r] == 0)
            cout << " ";
         else
            cout << board[c][r];
         if (c == 2 || c == 5)
         {
            cout << "|";
         }
         else
            if ( c != 8)
            {
               cout << " ";
            }
         if (c == 8)
         {
            cout << endl;
         }
      }
      if (r == 2 || r == 5)
         cout << "   -----+-----+-----\n";
   }
   cout << endl;
   return;
}

/*************************************************************************
 * Interact()
 ************************************************************************/
void interact(int board[][9], char &input)
{
   int r = 0;
   char c = '\0';
   do
   {
      cout << "> ";
      cin >> input;
      switch (input)
      {
         case '?':
            displayoptions();
            cout << endl;
            break;
         case 'd':
            displayboard(board);
            break;
         case 'D':
            displayboard(board);
            break;
         case 'e':
            getCoordinates(r, c);
            editSquare(board, r, c);
            break;
         case 'E':
            getCoordinates(r, c);
            editSquare(board,r,c);
            break;
         case 's':
            getCoordinates(r, c);
            displayPossible(board, r, c);
            break;
         case 'S':
            getCoordinates(r, c);
            displayPossible(board, r, c);
            break;
      }
   }
   while (input != 'q' && input != 'Q');
}

/**********************************************************************
 * writefile
 ***********************************************************************/
void writeFile(int sudokuBoard[][9])
{
   ofstream fout;
   char destinationFile[256];
   cout << "What file would you like to write your board to: ";
   cin  >> destinationFile;
   fout.open(destinationFile);
   if (fout.fail())
   {
      cout << "Output file opening failed.\n";
      return;
   }
   else
      cout << "Board written successfully\n";
   for (int col = 0; col < 9; col++)
   {
      for (int row = 0; row < 9; row++)
      {
         fout << sudokuBoard[row][col];
         if (row != 8)
         {
            fout << " ";
         }
         if (row == 8)
         {
            fout << endl;
         }
      }
   }
   fout.close();
}

/**********************************************************************
 * getCoordinates
 ***********************************************************************/
void getCoordinates(int &r, char &c)
{
   cout << "What are the coordinates of the square: ";
   cin  >> c >> r;
   return;
}

/**********************************************************************
 * editSquare()
 ***********************************************************************/
void editSquare(int board[][9],int r, char c)
{
   int value = 0;
   c = toupper(c);
   if (board[c - 65][r - 1] != 0)
   {
      cout << "ERROR: Square \'" << c << r << "\' is filled\n";
      cout << "\n";
      return;
   }
   else
   {
      cout << "What is the value at \'" << c << r << "\': ";
      cin  >> value;
      if (computeValues(r, c, board, value) == false)
      {
         cout << "ERROR: Value '" << value << "' in square '" << c << r << "' is invalid\n\n";
         return;
      }
                            
      cout << "\n";
      board[c - 65][r - 1] = value;
   }
}

/**********************************************************************
 * displayPossible(board)
 ***********************************************************************/
void displayPossible(int board[][9], int r, int c )
{
   for (int i = 1; i < 10; i++)
   {
      if (computePossible(r,c,board,i))
         cout << i;
   }
}

/**********************************************************************
 * computePossible(board)
 ***********************************************************************/
bool computeValues(int r, int c,int board[][9],int value)
{
   bool isValid = true;
   // loop x cord
   for (int k = 0; k < 9; k++)
   {
      if (board[r - 1][k] == value)
      {
         isValid = false;
      }
      if (board[k][c - 65] == value)
      {
         isValid = false;
      }
      if(value < 1 || value > 9)
      {
         isValid = false;
      }
   }
   return isValid;

}

/**********************************************************************
 * main function is to dedicate the variable to other functions
 ***********************************************************************/
int main()
{
   int board[9][9];
   char input = '\0';
   getFile(board);
   displayoptions();
   displayboard(board);
   interact(board, input);
   writeFile(board);
   return 0;
}
