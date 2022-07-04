#include<iostream>
using namespace std;
int main()
{
    int a[] = {0, 4, 8, 1, 5, 9, 2, 6, 10, 3, 7, 11};
    int initialize = 0, k = 0, i, M = 3, N = 4;
    int len = sizeof(a)/sizeof(a[0]);
    int b[len];
    // cout << len << endl;
    i = initialize;
    while(initialize <= N)
    {
        b[k] = a[i];
        k++;
        i += M;
        if(i >= len)
        {
            initialize++;
            i = initialize;
        }
    }
    for(int j=0; j<len; j++)
    {
        cout << b[j] << " ";
    }
}