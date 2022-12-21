/* Given an array, the task is to find the maximum sum of non adjacent elements.
Approach =>

There are two cases, either we pick the current element, or we don't pick 
the current element. 

1. If we pick the current element, then we add the current 
    element to the sum. In that case, we call the function recursively to the next 
    non adjacent element.

2. If we don't pick the current element, then we don't add the current element.
    In that case, we call the function recursively to the next adjacent element.

In the end, we return the maximum of two cases.

After applying Memoization ::

Time Complexity => O(n)
Space Complexity => O(n)

*/

#include<bits/stdc++.h>
using namespace std;
int maximumSumRecursion(int index, int arr[], vector<int> &vec)
{
    if(index == 0)
        return arr[index];
    
    if(index < 0)
        return 0;

    if(vec[index] !=  -1)
        return vec[index];
    
    int pick = arr[index] + maximumSumRecursion(index - 2, arr, vec);
    int notPick = 0 + maximumSumRecursion(index - 1, arr, vec);

    return vec[index] = max(pick, notPick);
}
int main()
{
    int arr[] = {2, 1, 4, 9};
    vector<int> vec(sizeof(arr)/sizeof(int), -1);
    cout << maximumSumRecursion(sizeof(arr)/sizeof(int) - 1, arr, vec);
}