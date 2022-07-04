#include<iostream>
using namespace std;
int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int k = 0, M = 3, N = 4, i = 0, j = 0;
    int len = sizeof(a)/sizeof(a[0]);
    int b[M][N];
    while(k < len)
    {
       b[i][j] = a[k];
       j++;
       k++;
       if(k % N == 0)
       {
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