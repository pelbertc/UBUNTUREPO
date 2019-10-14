#include <iostream>
#include <fstream>
using namespace std;

void getFile(char fileName[])
{
   cout << "Enter source filename: ";
   cin >> fileName;
   return;
}

int readFile(char tictac[][12])
{
   char fileName[256];
   getFile(fileName);
   ifstream file(fileName);
   if (file.fail())
   {
      //return error message if file cannot be read
      cout << "Error reading file: " << fileName << endl;
      return 0;
   }
   
   int numCharac = 0;
   while (file >> tictac[numCharac])
   {
      numCharac++;
   }

   
   file.close();
 
}

void display (char tictac[][12], int numCharac)
{ 
   for (int i = 0; i < numCharac; i++)
   {
      if(i == 2 || i == 5)
      {
	cout << tictac[i] << '\n';
      }else{
	cout << " " << tictac[i] << " ";
      }

      cout << "_";
      
   }
   cout << endl;
   
}

int main()
{
   char tictac[12][12];
   int numCharac;
   numCharac = readFile(tictac);
   display (tictac, numCharac);   

   char fileout[256];
   cout << "What destination filename: " << endl;
   cin >> fileout;
   ofstream fout(fileout);

   for(int i = 0; i < numCharac; i++)
     {
       fout << tictac[i] << endl;
     }
   fout.close();
}
