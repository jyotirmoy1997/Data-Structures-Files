#include<bits/stdc++.h>
using namespace std;
void rec(int index, vector<int> &nums, vector<int> &temp, vector<vector<int>> &res){
    res.push_back(temp);
    for(int i=index; i<nums.size(); i++){
        if(i > index && nums[i] == nums[i-1])
            continue;
        
        temp.push_back(nums[i]);
        rec(i + 1, nums, temp, res);
        temp.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums){
    vector<vector<int>> res;
    vector<int> temp;
    sort(nums.begin(), nums.end());
    rec(0, nums, temp, res);
    return res;
}
int main(){
    vector<int> nums = {1,2,2};
    auto res = subsetsWithDup(nums);
    for(auto it : res){
        for(auto el : it)
            cout << el << " ";
        
        cout << endl;
    }
}