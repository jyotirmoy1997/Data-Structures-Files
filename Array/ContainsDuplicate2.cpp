#include<bits/stdc++.h>
using namespace std;
bool containsNearbyDuplicate(vector<int>& nums, int k){
    unordered_map<int, int> mpp;
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(mpp.find(nums[i]) == mpp.end())
            mpp[nums[i]] = i;
        
        else if(i - mpp[nums[i]] > k)
            mpp[nums[i]] = i;

        else if(i - mpp[nums[i]] <= k)
            return true;
    }
    return false;
}
int main(){
    vector<int> nums = {1,2,3,1};
    int k = 3;
    cout << containsNearbyDuplicate(nums, 3);
}