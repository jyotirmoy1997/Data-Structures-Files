#include<bits/stdc++.h>
using namespace std;
int func(int i, int j, string s1, string s2){
    if(j < 0)
        return 1;
    if(i < 0)
        return 0;

    if(s1[i] == s2[j])
        return func(i-1, j-1, s1, s2) + func(i-1, j, s1, s2);
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