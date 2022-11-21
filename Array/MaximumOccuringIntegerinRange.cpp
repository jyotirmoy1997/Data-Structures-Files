/* Given n ranges, find the maximum appearing element in n ranges*/
#include <bits/stdc++.h>
using namespace std;
int maximumOccuringInteger(int L[], int R[], int n)
{
    vector<int> arr(1000, 0);
    for(int i=0; i<n; i++){
        arr[L[i]]++;
        arr[R[i] + 1]--;
    }
    int max = arr[0], res = 0;
    for(int i=1; i<1000; i++){
        arr[i] += arr[i-1];
        if(max < arr[i]){
            max = arr[i];
            res = i;
        }
    }
    return res;
}

int main()
{
    int L[] = { 1, 4, 9, 13, 21 };
    int R[] = { 15, 8, 12, 20, 30 };
    int n = sizeof(L) / sizeof(L[0]);
    cout << maximumOccuringInteger(L, R, n) << endl;
    return 0;
}