#include<bits/stdc++.h>
using namespace std;
 bool isAnagram(string s, string t) {
    if(s.size() != t.size())
        return false;

    unordered_map<char, int> mp1;
    unordered_map<char, int> mp2;

    int n = s.size();
    for(int i=0; i<n; i++)
        mp1[s[i]] += 1;
    
    int m = t.size();
    for(int i=0; i<m; i++)
        mp2[t[i]] += 1;

        
    for(auto it : mp1){
        auto ch = it.first;
        auto val = it.second;
        if(val != mp2[ch])
            return false;
    }
    return true;
}
int main(){
    cout << isAnagram("cat", "rat");
}