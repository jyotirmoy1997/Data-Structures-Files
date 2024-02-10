#include<bits/stdc++.h>
using namespace std;
void updateLongestPalindrome(string &s, int &left, int &resLen, int l, int r){
    int len = s.length();
    while(l >= 0 && r < len && s[l] == s[r]){
        if(r - l + 1 > resLen){
            left = l;
            resLen = r - l + 1;
        }
        l--;
        r++;
    }
}
string longestPalindrome(string s) {
    int left = -1, len = s.length(), resLen = 0;
    for(int i=0; i<len; i++){

        // Find Odd Length Palindromes
        int l = i, r = i;
        updateLongestPalindrome(s, left, resLen, l, r);

        // Find Even Length Palindromes
        l = i, r = i+1;
        updateLongestPalindrome(s, left, resLen, l, r);
    }
    return (resLen == 0) ? "" : s.substr(left, resLen);
}
int main(){

}