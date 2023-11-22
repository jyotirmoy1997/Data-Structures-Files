#include<bits/stdc++.h>
using namespace std;
bool isValid(unordered_map<char, int> &mps, unordered_map<char, int> &mpt){
    for(auto it : mps){
        if(mps[it.first] < mpt[it.first])
            return false;
    }
    return true;
}
string minWindow(string s, string t){
    int n = s.length(), m = t.length();
    if(m > n)
        return "";

    unordered_map<char, int> mpt;
    for(auto it : t)
        mpt[it]++;

    unordered_map<char, int> mps;
    int right = 0, left = 0, mini = INT_MAX, rmin = n, lmin = -1 ;
    while(right < n){
        if(mpt.find(s[right]) != mpt.end())
            mps[s[right]]++;

        while(mps.size() >= mpt.size() && isValid(mps, mpt)){
            if(right - left + 1 < mini){
                mini = right - left + 1;
                lmin = left;
                rmin = right;
            }
            if(mps.find(s[left]) != mps.end())
                mps[s[left]]--;

            if(mps.find(s[left]) != mps.end() && mps[s[left]] == 0)
                mps.erase(s[left]);

            left++;
        }
        right++;
    }
    string res = (lmin == -1) ? "" : s.substr(lmin, mini);
    return res;
}
int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t);
}