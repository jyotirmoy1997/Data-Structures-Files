/* Given an array, the task is to find the maximum sum of a sub array*/

/* Kadane's Algorithm :: Here, we are storing the ending position of the maximum sum. Then 
we consider the next element; If the next element alone is greater than the 
maximum sum, then we discard the previous maximum sum and update the 
maximum sum with the current element, else we add the current element 
to the maximum sum. */

#include<bits/stdc++.h>
using namespace std;
int maxSumSubArray(int arr[], int n)
{
   int res = arr[0], max_ending = arr[0];
   for(int i=1; i<n; i++)
   {
    max_ending = max(max_ending + arr[i], arr[i]);
    res = max(res, max_ending);
   }
   return res;
}
int main()
{
    int arr[] = {5, -2, 3, 4};
    cout << maxSumSubArray(arr, sizeof(arr)/sizeof(int));
    return 0;
}