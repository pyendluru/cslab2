#include <iostream>
void funcA(int*,int);
void funcB(int *a,int min,int max);
using namespace std;

int main()
{
	int a[5]={1,2,3,4,5};
	funcA(a,5);
	return 0;
}

void funcA (int *a, int size) {
    funcB(a, 0, size-1);
}

void funcB(int *a, int min, int max) {
    if (min == max)
        cout << a[min] << endl;
    else {
        int mid = (min+max)/2;
        funcB(a, min, mid);
        funcB(a, mid+1, max);
    }
}