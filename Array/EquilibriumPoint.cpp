#include <bits/stdc++.h>
using namespace std;
int equilibriumPoint(int arr[], int n)
{
    int sum = accumulate(arr, arr+n, 0);
    if(arr[0] == (sum-arr[0])){
        return arr[0];
    }
    if(arr[n-1] == (sum-arr[n-1])){
        return arr[n-1];
    }
    int left = arr[0], right;
    for(int i=1; i<n-1; i++){
        right= sum - arr[i] - left;
        if(right == left){
            return arr[i];
        }
        left += arr[i];
    }
    return -1;
}

int main()
{
    int arr[] = {3, 4, 8, -9, 20, 6};
    cout << equilibriumPoint(arr, sizeof(arr)/sizeof(arr[0]));
}