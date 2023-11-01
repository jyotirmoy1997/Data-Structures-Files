#include<bits/stdc++.h>
using namespace std;
void rec(int index, int n, int k, vector<int> &temp, vector<vector<int>> &res){
    if(n < 0 || temp.size() > k)
        return;
    
    if(n == 0 && temp.size() == k){
        res.push_back(temp);
        return;
    }

    for(int i=index; i<=9; i++){
        temp.push_back(i);
        rec(i + 1, n-i, k, temp, res);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n){
    vector<int> temp;
    vector<vector<int>> res;
    rec(1, n, k, temp, res);
    return res;
}
int main(){
    auto res = combinationSum3(3, 7);
    for(auto it : res){
        for(auto el : it)
            cout << el << " ";
        
        cout << endl;
    }
}