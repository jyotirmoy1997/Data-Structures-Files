#include<bits/stdc++.h>
using namespace std;
bool isSubsequence(string s, string t) {
    int m = s.length(), n = t.length(), i = 0, j = 0;
    while(i < n){
        if(s[j] == t[i])
            j++;
        
        i++;
    }
    return (j == m) ? true : false;
}
int main(){
    string s = "axc";
    string t = "ahbgdc";
    cout << isSubsequence(s, t);
}