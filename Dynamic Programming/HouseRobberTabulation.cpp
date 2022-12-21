/* Given an array, the task is to find the maximum sum of non adjacent elements.

Note =>  In this case, the first and the last eleents are adjacent.

Approach =>

Apply tabulation on the array without the first element.
Re-apply tabulation on the array without the last element.

Then return the max of the two.


Time Complexity => O(n)
Space Complexity => O(n)

*/

#include<bits/stdc++.h>
using namespace std;
int maximumSumTabulation(int index, vector<int> &arr)
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
long long int houseRobber(int arr[], int n){
    vector<int> temp1, temp2;
    for(int i=0; i<n; i++){
        if(i != 0)
            temp1.emplace_back(arr[i]);
        if(i != n-1)
            temp2.emplace_back(arr[i]);
    }
    return max(maximumSumTabulation(temp1.size()-1, temp1), maximumSumTabulation(temp2.size()-1, temp2));
}
int main()
{
    int arr[] = {2, 1, 4, 9};
    int n = sizeof(arr)/sizeof(int);
    cout << houseRobber(arr, n);
}