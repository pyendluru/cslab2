#include <iostream>
#include <fstream>
using namespace std;

//This function will print file with words reversed.
void PrintReverse(ifstream stream, int length)
{
    string letters;
    stream >> letters;
    if(length > 0)
        PrintReverse(stream, length-1);
    cout << letters << " ";  
}

int main(int word, char* words[])
{
    ifstream stream;
    stream.open(words[1]);   //From, the terminal will open the hw1q6.txt file
    int count;      
    stream >> count;               //Will extract first value from file
    PrintReverse(stream, count);   //The recursive function will print 
    cout << endl;
    return 0;
}