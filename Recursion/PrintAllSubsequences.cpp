#include<bits/stdc++.h>
using namespace std;
void rec(vector<vector<int>> &res, vector<int> &temp, vector<int> &nums, int index){
    if(index == nums.size()){
        res.push_back(temp);
        return;
    }
    // Take the element
    temp.push_back(nums[index]);
    rec(res, temp, nums, index + 1);

    // Don't take the element
    temp.pop_back();
    rec(res, temp, nums, index + 1);
}
vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> res;
    vector<int> temp;
    int index = 0;
    rec(res, temp, nums, index);
    return res;
}
int main(){
    vector<int> nums = {1, 2, 3};
    auto res = subsets(nums);
    for(auto it : res){
        for(auto el : it)
            cout << el << " ";
        
        cout << endl;
    }
}