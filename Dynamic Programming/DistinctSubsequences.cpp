#include<bits/stdc++.h>
using namespace std;
int func(int i, int j, string s1, string s2){
    // string 2 has been exhausted/completely matched. return 1
    if(j < 0)
        return 1;

    // string 1 is exhausted and there are still some 
    // characters left in string s2. thus we cannot match further. return 0;
    if(i < 0)
        return 0;

    // If both the characters match, then either we shrink both string 1 and string 2 by 1
    // or, we can shrink only string 1 and keep string 2 intact stating that
    // we can match it further.
    if(s1[i] == s2[j])
        return func(i-1, j-1, s1, s2) + func(i-1, j, s1, s2);

    // If they do not match, simply shrink string 1 by 1 and keep string 2 intact
    else
        return func(i-1, j, s1, s2);
}
int distinctSubsequences(string s1, string s2){
    int i = s1.length()-1;
    int j = s2.length()-1;
    return func(i, j, s1, s2);
}
int main(){
    string s1 = "babgbag";
    string s2 = "bag";
    cout << distinctSubsequences(s1, s2);
}