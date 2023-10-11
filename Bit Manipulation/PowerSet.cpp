#include<bits/stdc++.h>
using namespace std;
// (1 << n) means 2^n
vector<vector<int>> subsets(vector<int> &nums){
    int n = nums.size();
    int totalSubsets = 1 << n;
    vector<vector<int>> res;

    for (int i = 0; i < totalSubsets; i++) {
        vector<int> subset;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset.push_back(nums[j]);
            }
        }
        res.push_back(subset);
    }
    return res;
}
int main(){
    vector<int> nums = {3, 2, 4};
    auto res = subsets(nums);
    for(auto it : res){
        for(auto el : it)
            cout << el << " ";
        
        cout << endl;
    }
}