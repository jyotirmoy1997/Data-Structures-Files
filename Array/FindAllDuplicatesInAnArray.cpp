#include<bits/stdc++.h>
using namespace std;
vector<int> findDuplicates(vector<int>& nums) {
    vector<int>result;
    int n = nums.size();
    for(int i=0; i<n; i++){
        int num =abs(nums[i]);
        int idx = num - 1;
        if(nums[idx] < 0)
            result.push_back(num);
        
        nums[idx] *= -1;
    }
    return result;
}
int main(){
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    auto res = findDuplicates(nums);
    for(auto it : res)
        cout << it << " ";
}