#include <iostream>
#include <fstream>
using namespace std;

//This function will print file with words reversed.

void PrintReverse(ifstream &stream, int length)
{
    string letters;
    stream >> letters;
        PrintReverse(stream, length-1);
    cout << letters << " ";  
}
/* The main below will first open text file from the command line.
Then it will extract first value as number of strings.
Then finally uses the function above to print in reverse*/

int main(int word, char* words[])
{
    ifstream stream;
    stream.open(words[1]);   
    int count;      
    stream >> count;               
    PrintReverse(stream, count); 
    cout << endl;
    return 0;
}