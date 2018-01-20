#include <iostream>
#include <fstream>
using namespace std;

//This function will print file with words reversed.
void PrintReverse(ifstream &fin, int length)
{
    string letters;
    fin >> letters;
    if(length > 0)
        PrintReverse(fin, length-1);
    cout << letters << " ";  
}

int main(int word, char* words[])
{
    ifstream fin;
    fin.open(words[1]);   //From, the terminal will open the hw1q6.txt file
    int count;      
    fin >> count;               //Will extract first value from file
    PrintReverse(fin, count);   //The recursive function will print 
    cout << endl;
    return 0;
}