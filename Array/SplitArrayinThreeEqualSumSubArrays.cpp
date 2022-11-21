/* Given an array, the task is to determine if the array can be split into 
3 equal sum sub arrays or not

An efficient solution is to first find the sum S of all array elements. 
Check if this sum is divisible by 3 or not. This is because if sum is not 
divisible then the sum cannot be split in three equal sum sets. 
If there are three contiguous subarrays with equal sum, then sum of each subarray is S/3. 
Suppose the required pair of indices is (i, j) such that sum(arr[0..i]) = sum(arr[i+1..j]) = S/3. 
Also sum(arr[0..i]) = preSum[i] and sum(arr[i+1..j]) = preSum[j] – preSum[i]. 
This gives preSum[i] = preSum[j] – preSum[i] = S/3. This gives preSum[j] = 2*preSum[i]. 
Thus, the problem reduces to find two indices i and j such that preSum[i] = S/3 and preSum[j] = 2*(S/3). 
For finding these two indices, traverse the array and store sum upto current 
element in a variable preSum. Check if preSum is equal to S/3 and 2*(S/3).
 */
#include <bits/stdc++.h>
using namespace std;
pair<int, int> splitPoint(int arr[], int n)
{
    pair<int, int> res;
    res.first = -1;
    res.second = -1;
    int sum = accumulate(arr, arr+n, 0);
    if(sum % 3 != 0){
        return make_pair(-1, -1);
    }
    int preSum = 0;
    for(int i=0; i<n; i++){
        preSum += arr[i];
        if(preSum == sum/3 && res.first == -1)
            res.first = i;
        else if(preSum == (2*sum)/3 && res.first != -1){
            res.second = i;
        }
    }
    return res;
}

int main()
{
    int arr[] = {5, 2, 6, 1, 1, 1, 5};
    auto point = splitPoint(arr, sizeof(arr)/sizeof(arr[0]));
    cout << point.first << " " << point.second;
}