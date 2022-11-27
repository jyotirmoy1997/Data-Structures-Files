/* Given a sorted array, the task is to find a pair such that it matches the target sum.

We use the two pointer approach here. */
#include <bits/stdc++.h>
using namespace std;
pair<int, int> twoSumSorted(int arr[], int n, int s)
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
            return make_pair(arr[start], arr[end]);
    }
    return make_pair(-1, -1);
}

int main()
{
    int arr[] = {2, 5, 8, 12, 30};
    auto res = twoSumSorted(arr, sizeof(arr)/sizeof(arr[0]), 17);
    cout << res.first << " " << res.second;
}