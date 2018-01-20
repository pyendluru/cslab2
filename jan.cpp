#include <iostream>
#include <fstream>
using namespace std;

//This function will print file with words reversed.

void PrintReverse(ifstream &stream, int Stringcount)
{
    string letters;
    stream >> letters;
    if(Stringcount > 0)
        PrintReverse(stream, Stringcount-1);
    cout << letters << " ";  
}

/* The main below will first open text file from the command line.
Then it will extract first value as number of strings.
Then finally uses the function above to print in reverse*/

int main(int word, char* words[])
{
    int count;
    ifstream stream;
    stream.open(words[1]);         
    stream >> count;               
    PrintReverse(stream, count); 
    cout << endl;
    return 0;
}