
#include <iostream>
#include <fstream>
using namespace std;

//Prints the file with words reversed.
void readFilePrintReverse(ifstream &fin, int size)
{
    string word;
    fin >> word;
    if(size > 0)
        readFilePrintReverse(fin, size-1);
    cout << word << " ";  
}

int main(int argc, char* argv[])
{
    ifstream fin;
    fin.open(argv[1]);   //Reads the file from the command line argument.
    int count;      
    fin >> count;       //Reads the first value from the file as integer.
    readFilePrintReverse(fin, count);   //Calls the recursive function to print the file.
    cout << endl;
}