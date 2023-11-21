#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s){
    unordered_map<char, int> mpp;
    int l = 0, r = 0, n = s.length(), maxLen = 0;
    while(r < n){
        if(mpp.find(s[r]) != mpp.end())
            l = max(mpp[s[r]] + 1, l);

        mpp[s[r]] = r;
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}
int main(){
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);
}