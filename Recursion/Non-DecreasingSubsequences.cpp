#include<bits/stdc++.h>
using namespace std;
void rec(int index, int prev, int n, vector<int> &nums, set<vector<int>> &st, vector<int> &temp){
    if(index == n){
        if(temp.size() >= 2)
            st.insert(temp);
        
        return;
    }
    // Take Case
    temp.push_back(nums[index]);
    if(nums[index] >= prev)
        rec(index + 1, nums[index], n, nums, st, temp);

    // Not Take Case
    temp.pop_back();
    rec(index + 1, prev, n, nums, st, temp);
}
vector<vector<int>> findSubsequences(vector<int> &nums){
    int index = 0, prev = -101, n = nums.size();
    vector<int> temp;
    set<vector<int>> st;
    rec(index, prev, n, nums, st, temp);
    vector<vector<int>> ans;
    for(auto it : st)
        ans.push_back(it);
    
    return ans;
}
int main(){
    vector<int> nums = {4, 6, 7, 7};
    auto res = findSubsequences(nums);
    for(auto it : res){
        for(auto el : it)
            cout << el << " ";
        
        cout << endl;
    }
}