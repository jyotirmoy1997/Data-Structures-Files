#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> findMatrix(vector<int>& nums) {
    unordered_map<int, int> freq;
    int maxFreq = 0;
    for (auto it : nums) {
        freq[it]++;
        maxFreq = max(maxFreq, freq[it]);
    }
    vector<vector<int>> res(maxFreq);
    for (auto& pair : freq) {
        int value = pair.first;
        int frequency = pair.second;
        
        for (int i = 0; i < frequency; i++)
            res[i].push_back(value);
        
    }
    return res;
}
int main(){
    vector<int> nums = {1,3,4,1,2,3,1};
    auto res = findMatrix(nums);
    for(auto it : res){
        for(auto el : it)
            cout << el << " ";
        
        cout << endl;
    }
}