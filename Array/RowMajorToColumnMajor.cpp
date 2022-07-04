#include<iostream>
using namespace std;
int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int initialize = 0, k = 0, i, M = 3, N = 3;
    int len = sizeof(a)/sizeof(a[0]);
    int b[len];
    // cout << len << endl;
    i = initialize;
    while(initialize <= M)
    {
        // cout << "Element :: " << a[i] << endl;
        // cout << "Initialize :: " << initialize << endl;
        // cout << "K :: " << k << endl;
        // cout << "i :: " << i << endl;
        // cout << endl;
        b[k] = a[i];
        k++;
        i += N;
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