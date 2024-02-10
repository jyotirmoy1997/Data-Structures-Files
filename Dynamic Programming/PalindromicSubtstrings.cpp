#include<bits/stdc++.h>
using namespace std;
int countPalindromes(string &s, int l, int r){
    int len = s.length(), res = 0;
    while(l >= 0 && r < len && s[l] == s[r]){
        res++;
        l--;
        r++;
    }
    return res;
}
int countSubstrings(string s) {
    int len = s.length(), res = 0;

    for(int i=0; i<len; i++){

        // Find Odd Length Palindromes
        int l = i, r = i;
        res += countPalindromes(s, l, r);

        // Find Even Length Palindromes
        l = i;
        r = i + 1;
        res += countPalindromes(s, l, r);
    }
    return res;
}
int main(){
    string s = "aaab";
    cout << countSubstrings(s);
}