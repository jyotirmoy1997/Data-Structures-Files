#include<bits/stdc++.h>
using namespace std;
int func(string s1, string s2, int ind1, int ind2, stack<char> &st){
    if(ind1 < 0 || ind2 < 0)
        return 0;
    
    if(s1[ind1] == s2[ind2]){
        st.push(s1[ind1]);
        return 1 + func(s1, s2, ind1-1, ind2-1, st);
    }
    
    return 0 + max(func(s1, s2, ind1-1, ind2, st), func(s1, s2, ind1, ind2-1, st));
}
void longestCommonSubsequence(string s1, string s2){
    stack<char> st;
    cout << func(s1, s2, s1.length(), s2.length(), st) << endl;
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        cout << it;
    }
}
int main(){
    string s1 = "acd";
    string s2 = "ced";
    longestCommonSubsequence(s1, s2);
}