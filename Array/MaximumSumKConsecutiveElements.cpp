/* Given an array, the task is to find the maximum maximum sub of k
consecutive elements (Sub array)*/

#include<bits/stdc++.h>
using namespace std;
int maxKSumSubArray(int arr[], int n, int k){
    int sum = arr[0];
    for(int i=1; i<k; i++){
        sum += arr[i];
    }
    int res = sum, c=0;
    for(int i=0+k; i<n; i++){
        sum += arr[i] - arr[c++];
        res = max(res, sum);
    }
    return res;
}
int main()
{
    int arr[] = {1, 8, 30, -5, 20, 7};
    cout << maxKSumSubArray(arr, sizeof(arr)/sizeof(int), 3);
}