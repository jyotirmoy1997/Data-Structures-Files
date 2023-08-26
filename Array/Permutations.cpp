/* 
 */

#include<bits/stdc++.h>
using namespace std;
void generatePermutations(vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans, vector<int> &fr){
    // Base Case
    if(ds.size() == arr.size()){
        ans.push_back(ds);
        return;
    }
        

    for(int i=0; i<arr.size(); i++){
        if(fr[i] == 0){
            ds.push_back(arr[i]);
            fr[i] = 1;
            generatePermutations(arr, ds, ans, fr);
            ds.pop_back();
            fr[i] = 0;
        }
    }
}   
int main(){
    vector<int> arr = {3, 1, 2};
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> fr(arr.size(), 0);
    generatePermutations(arr, ds, ans, fr);
    for(auto it : ans){
        for(auto el : it){
            cout << el << " ";
        }
        cout << endl;
    }
}