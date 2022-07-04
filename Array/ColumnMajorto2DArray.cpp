#include<iostream>
using namespace std;
int main()
{
    int a[] = {0, 4, 8, 1, 5, 9, 2, 6, 10, 3, 7, 11};
    int initialize = 0, k = 0, i = 0, j = 0, M = 3, N = 4;
    int len = sizeof(a)/sizeof(a[0]);
    int b[M][N];
    // cout << len << endl;
    k = initialize;
    while(initialize <= N)
    {
        // cout << "Element :: " << a[i] << endl;
        // cout << "Initialize :: " << initialize << endl;
        // cout << "K :: " << k << endl;
        // cout << "i :: " << i << endl;
        // cout << endl;
        b[i][j] = a[k];
        k += M;
        j++;
        if(k >= len)
        {
            initialize++;
            k = initialize;
            i++;
            j = 0;
        }
    }
    for(int m=0; m<M; m++)
    {
        for(int n=0; n<N; n++)
        {
            cout << b[m][n] << " ";
        }
        cout << endl;
    }
}