#include<bits/stdc++.h>
using namespace std;
int numberOfSubstrings(string s){
    unordered_map<char, int> mpp;
    int l = s.length(), res = 0, start = 0, end = 0;
    while(start < l){
        mpp[s[start]]++;
        while(mpp['a'] >= 1 && mpp['b'] >= 1 && mpp['c'] >= 1){
            res += (l - start);
            mpp[s[end]]--;
            end++;
        }
        start++;
    }
    return res;
}
int main(){
    string s = "abcabc";
    cout << numberOfSubstrings(s);
}