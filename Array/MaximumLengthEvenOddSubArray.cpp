/* Given an array, the task is to find the Longest stream of alternating 
Even-Odd elements. */

#include<bits/stdc++.h>
using namespace std;
int maxLenEvenOdd(int arr[], int n){
    int res = 1, curr = 1;
    for(int i=0; i<n-1; i++)
    {
        if(arr[i] % 2 == 0 && arr[i+1] % 2 != 0 ||
           arr[i] % 2 != 0 && arr[i+1] % 2 == 0)
           {
                curr++;
                res = max(curr, res);
           }
           else{
            curr = 1; 
           }
    }
    return res;
}
int main()
{
    int arr[] = {10, 12, 14, 7, 8};
    cout << maxLenEvenOdd(arr, sizeof(arr)/sizeof(int));
}