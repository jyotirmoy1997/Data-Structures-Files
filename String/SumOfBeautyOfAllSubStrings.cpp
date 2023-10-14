#include <bits/stdc++.h>
using namespace std;
int beautySum(string s){
    int sum = 0, l = s.length();
    unordered_set<string> st;
    for(int i=0; i<l; i++){
        unordered_map<char, int> freq;
        for(int j=i; j<l; j++){
            freq[s[j]] += 1;
            int maxi = INT_MIN, mini = INT_MAX;
            for(auto it : freq){
                maxi = max(it.second, maxi);
                mini = min(it.second, mini);
            }
            sum += maxi - mini;
        }
    }
    return sum;  
}
int main() {
    string s = "aabcbaa";
    cout << beautySum(s);
    return 0;
}
