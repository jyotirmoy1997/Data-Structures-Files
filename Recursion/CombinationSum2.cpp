#include<bits/stdc++.h>
using namespace std;
void rec(vector<int> &candidates, int target, int index, vector<int> &temp, vector<vector<int>> &res){
    if(target == 0){
        res.push_back(temp);
        return;
    }


    for(int i=index; i<candidates.size(); i++){
        if(i > index && candidates[i] == candidates[i-1])
            continue;
        
        if(candidates[i] > target)
            break;
        
        temp.push_back(candidates[i]);
        rec(candidates, target-candidates[i], i + 1, temp, res);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> temp;
    rec(candidates, target, 0, temp, res);
    return res;
}
int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    auto res = combinationSum2(candidates, 8);
    for(auto it : res){
        for(auto el : it)
            cout << el << " ";
        
        cout << endl;
    }
}