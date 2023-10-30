#include<bits/stdc++.h>
using namespace std;
string moreSubsequence(int n, int m, string a, string b){
    set<char>s1;
    set<char>s2;
    for(int i=0; i<n; i++) 
        s1.insert(a[i]);
    for(int i=0; i<m; i++) 
        s2.insert(b[i]);
    if(s1.size()==s2.size())
        return n < m ? b : a;
    else 
        return s1.size() < s2.size() ? b : a;
}
int main(){
    string a = "ab";
    string b = "dd";
    cout << moreSubsequence(a.size(), b.size(), a, b);
}