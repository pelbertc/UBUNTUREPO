#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
bool row(int s,int o,int n);
bool column(int s,int o,int n);
bool square(int s,int o,int n);

int sudokuGrid[9][9];

bool row(int s,int o,int n)
{
   for(int g=0;g<9;g++)
   {

      if(sudokuGrid[s][g]==n)
      {
         return 0;
      }
   }
   return 1;
}
bool column(int s,int o,int n)
{
   for(int g=0;g<9;g++)
   {
      if(sudokuGrid[g][o]==n)
         return 0;
   }
   return 1;
}
bool square(int s,int o,int n)
{
   int row=ceil((s+1)/3.);
   int column=ceil((o+1)/3.);
   for(int g=(row-1)*3;g<((row-1)*3+3);g++)
      for(int h=(column-1)*3;h<((column-1)*3+3);h++)
      {
         if(sudokuGrid[g][h]==n)
            return 0;
      }
   return 1;
}

void getFilename(char fileName[])
{
	cout << "Give the sudoku filename: ";
	cin >> fileName;
}

void computeValue(int space, bool solver, int filler)
{
while(space && solver)
{
   solver=0;
   for(int i=0;i<9;i++)
   {
      for(int j=0;j<9;j++)
      {
         if(sudokuGrid[i][j]!=0)
            continue;
         filler=0;
         for(int x=1;x<10;x++)
         {
            if(row(i,j,x) && column(i,j,x) && square(i,j,x))
            {
               if(filler==0)
                  filler=x;
               else{
                  filler=0;
                  break;
               }
            }
         }
         if(filler!=0)
         {
            sudokuGrid[i][j]=filler;
            solver=1;
            space--;
         }
      }
   }
}
if(!solver)
   cout << "It cannot be solved" << endl;
else if(!space)
   cout << "solved" << endl;
cout << endl;

for(int i=0;i<9;i++)
{
   for(int j=0;j<9;j++)
   {
      cout << sudokuGrid[i][j] << " ";
   }
   cout << endl;
}
cout << endl;

}

int main()
{
   int space=0,s,o,filler;
   bool solver=1;
   char file[20];
   cout << "write it manually (k) or read from file (f)? ";
   cin >> file[0];
   if(file[0]=='f')
   {
      getFilename(file);
      cout << endl;
      ifstream in(file);
      for(int i=0;i<9;i++)
      {
         for(int j=0;j<9;j++)
         {
            in >> sudokuGrid[i][j];
            if(!sudokuGrid[i][j])
               space++;
         }
      }
      in.close();
   }else if(file[0]=='k')
   {
      for(int i=0;i<9;i++)
         for(int j=0;j<9;j++)
         {
            do{
               cout << "Please enter " << i+1 << ". row " << j+1 << ". number: ";
               cin >> sudokuGrid[i][j];
            }while(sudokuGrid[i][j]<=0 && sudokuGrid[i][j]>10);
            if(sudokuGrid[i][j]==0)
               space++;
         }
   }else
   {
      cout << "exiting..." << endl;
      return 0;
   }

   computeValue(space, solver, filler);
}   



