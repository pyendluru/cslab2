#include <iostream>

#include <stdlib.h>

#include <cstring>

using namespace std;

bool increasing(int a)

{

if (a > 0) {

if (increasing (a/10)) return false;

int last = a % 10;

int prev = (a / 10) % 10;

if (prev <= last){

//Recursive Function Call

increasing(a/10);

return true;

}

return false;

}

return false;

}

int main (int argc, char* argv[])

{

if(argc < 2){

cerr << "Please provide an integer." << endl;

return 1;

}

int x = atoi(argv[1]);

if(increasing(x)) cout << "Increasing order." << endl;

else cout << "Not increasing order." << endl;

return 0;

}

