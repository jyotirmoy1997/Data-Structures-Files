/* Given a sorted array, the task is to find a triplet such that it matches the target sum.

We use the two sum approach along with an additional loop. The time complexity is 
thereby O(n2) */
#include <bits/stdc++.h>
using namespace std;
bool twoSumSorted(int arr[], int n, int s)
{
    int start = 0, end = n-1;
    while(start < end)
    {
       
        int sum = arr[start] + arr[end];
        if(sum > s){
            end--;
        }
        else if(sum < s){
            start++;
        }
        else
            return true;
    }
    return false;
}
bool threeSumSorted(int arr[], int n, int s){
    for(int i=0; i<n; i++){
        if(twoSumSorted(arr, n, s-arr[i]))
            return true;
    }
    return false;
}
int main()
{
    int arr[] = {2, 3, 4, 8, 9, 20, 40};
    cout << threeSumSorted(arr, sizeof(arr)/sizeof(arr[0]), 32);
}