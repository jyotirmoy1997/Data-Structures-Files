#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> divideArray(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for(int i=0; i<n; i+=3){
        if(nums[i+2] - nums[i] > k)
            return vector<vector<int>>();
        
        vector<int> vec;
        for(int j=i; j<i+3; j++)
            vec.push_back(nums[j]);
        
        res.push_back(vec);
    }
    return res;
}
int main(){
    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    int k = 2;
    auto res = divideArray(nums, k);
    for(auto it : res){
        for(auto el : it)
            cout << el << " ";

        cout << endl;
    }
}