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

After applying Tabulation ::

Time Complexity => O(n)
Space Complexity => O(n)

*/

#include<bits/stdc++.h>
using namespace std;
int maximumSumRecursion(int index, int arr[])
{
    vector<int> vec(index, -1);
    vec[0] = arr[0];
    for(int i=1; i<=index; i++)
    {
        int pick = arr[i];
        if(i > 1)
            pick += vec[i-2];

        int notPick = vec[i-1];

        vec[i] = max(pick, notPick);
    }
    return vec[index];
}
int main()
{
    int arr[] = {2, 1, 4, 9};
    int n = sizeof(arr)/sizeof(int) - 1;
    cout << maximumSumRecursion(n, arr);
}