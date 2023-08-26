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
void printMaxSumSubArray(int arr[], int n){
    int sum = 0, maximum = INT_MIN, start, ansStart, ansEnd;
    for(int i=0; i<n; i++){
        if(sum == 0)
            start = i;

        sum += arr[i];
        if(sum > maximum){
            maximum = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum < 0)
            sum = 0;
    }
    cout << ansStart << " " << ansEnd;
}
int main()
{
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    // cout << maxSumSubArray(arr, sizeof(arr)/sizeof(int));
    printMaxSumSubArray(arr, sizeof(arr)/sizeof(int));
    return 0;
}