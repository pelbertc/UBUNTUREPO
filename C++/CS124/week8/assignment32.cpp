#include <iostream>

using namespace std;

int countLetters(char text[], char letter)
{
  int count = 0;
  for(int i = 0; i < text[i] != '\0'; i++)
    {
      if(text[i] == letter)   
      count++;
    }

  return count;
}

int main()
{
  char letter;
  char text[256];

  cout << "Please enter a letter: " << endl;
  cin >> letter;

  cout << "Please enter string" << endl;
  cin.ignore();
  cin.getline(text,256);
  
  int count = countLetters(text, letter);
    cout << count << endl;
				   
}
