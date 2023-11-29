#include<bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, vector<int> &nums){
     int start = 0, end = 0, mini = INT_MAX, n = nums.size();
     long long sum = 0;
     while(start < n){
        sum += nums[start];
        while(sum > target){
            sum -= nums[end];
            end++;
        }
        if(sum == target)
            mini = min(mini, start - end + 1);

        start++;
     }
     return (mini == INT_MAX) ? 0 : mini;
}
int main(){
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << minSubArrayLen(target, nums);
}