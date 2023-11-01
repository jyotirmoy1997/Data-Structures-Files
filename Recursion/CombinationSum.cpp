#include<bits/stdc++.h>
using namespace std;
void rec(vector<int> &candidates, int target, int index, vector<int> &temp, vector<vector<int>> &res){
    if(target == 0){
        res.push_back(temp);
        return;
    }
    if(index == candidates.size()){
        if(target == 0)
            res.push_back(temp);
        
        return;
    }

    // Take Case
    if(candidates[index] <= target){
        temp.push_back(candidates[index]);
        rec(candidates, target - candidates[index], index, temp, res);
        temp.pop_back();
    }
    
    // not take Case
    rec(candidates, target, index + 1, temp, res);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target){
    vector<vector<int>> res;
    vector<int> temp;
    rec(candidates, target, 0, temp, res);
    return res;
}
int main(){
    vector<int> candidates = {2, 3, 6, 7};
    auto res = combinationSum(candidates, 7);
    for(auto it : res){
        for(auto el : it)
            cout << el << " ";
        
        cout << endl;
    }
}