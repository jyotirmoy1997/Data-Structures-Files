#include<bits/stdc++.h>
using namespace std;

// This is the Brute Force Solution
vector<vector<string>> groupAnagrams(vector<string> &strs){
    unordered_map<string, vector<string>> mpp;
    int n = strs.size();
    for(int i=0; i<n; i++){
        string s = strs[i];
        sort(s.begin(), s.end());
        if(mpp.find(s) == mpp.end()){
            vector<string> vec;
            vec.push_back(strs[i]);
            mpp[s] = vec;
        }
        else
            mpp[s].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for(auto it : mpp)
        ans.push_back(it.second);

    return ans;
}


// This is the Optimal Solution
string getKey(string str){
    vector<int> count(26, 0);
    for(auto it : str)
        count[it - 'a']++;

    string key = "";
    for(auto it : count)
        key += to_string(it) + '#';

    return key;
}
vector<vector<string>> groupAnagramsOptimal(vector<string> &strs){
    unordered_map<string, vector<string>> mpp;
    int n = strs.size();
    for(int i=0; i<n; i++){
        string key = getKey(strs[i]);
        mpp[key].push_back(strs[i]);
    }
    vector<vector<string>> ans;
    for(auto it : mpp)
        ans.push_back(it.second);

    return ans;
}
int main(){

}