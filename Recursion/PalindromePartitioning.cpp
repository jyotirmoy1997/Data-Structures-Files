#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if(s[start] != s[end])
            return false;
        
        start++;
        end--;
    }
    return true;
}
void rec(int index, string s, vector<string> &path, vector<vector<string>> &ans){
    if(index == s.size()){
        ans.push_back(path);
        return;
    }

    for(int i=index; i<s.size(); i++){
        if(isPalindrome(s, index, i)){
            path.push_back(s.substr(index, i - index + 1));
            rec(i + 1, s, path, ans);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string s){
    vector<vector<string>> ans;
    vector<string> path;
    rec(0, s, path, ans);
    return ans;
}
int main(){
    string s = "aab";
    auto res = partition(s);
    for(auto it : res){
        for(auto el : it)
            cout << el << " ";

        cout << endl;
    }
}