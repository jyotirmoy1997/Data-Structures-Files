#include<bits/stdc++.h>
using namespace std;
int atmostK(vector<int>& nums, int k){
    unordered_map<int, int> mpp;
    int n = nums.size(), right = 0, left = 0, res = 0;
    while(right < n){
        mpp[nums[right]]++;
        while(mpp.size() > k){
            mpp[nums[left]]--;
            if(mpp[nums[left]] == 0)
                mpp.erase(nums[left]);

            left++;
        }
        res += right - left + 1;
        right++;
    }
    return res;
}
int subarraysWithKDistinct(vector<int>& nums, int k){
    return atmostK(nums, k) - atmostK(nums, k-1);
}
int main(){
    vector<int> nums = {1,2,1,2,3};
    int k = 2;
    cout << subarraysWithKDistinct(nums, k);
}