#include<bits/stdc++.h>
using namespace std;
int atmostSubarray(vector<int> &nums, int goal){
    if(goal < 0)
        return 0;

    int start = 0, end = 0, sum = 0, res = 0, n = nums.size();
    while(end < n){
        sum += nums[end];
        while(sum > goal){
            sum -= nums[start];
            start++;
        }
        res += end - start + 1;
        end++;
    }
    return res;
}
int numSubarraysWithSum(vector<int>& nums, int goal){
    return atmostSubarray(nums, goal) - atmostSubarray(nums, goal - 1);
}
int main(){
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;
    cout << numSubarraysWithSum(nums, goal);
}