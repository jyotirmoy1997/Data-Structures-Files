/* The idea is to shift the goal back to zero from n-1. If we can reach 0, we
simply return true, else we return false */

#include<bits/stdc++.h>
using namespace std;
bool canJump(vector<int>& nums){
    int goal = nums.size() - 1, n = nums.size();
    for(int i=n-1; i>=0; i--){
        if(i + nums[i] >= goal)
            goal = i;
    }
    return (goal == 0) ? true : false;
}
int main(){
    vector<int> nums = {2,3,1,1,4};
    cout << canJump(nums);
}