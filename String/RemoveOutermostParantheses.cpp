/* Here, we keep a track of the level of the string. If the level is greater than 0, 
we simply add it to the result string. */

#include<bits/stdc++.h>
using namespace std;
string removeOuterParentheses(string s) {
    string p = "";
    stack<char> st;
    int l = s.length();
    int level = 0;

    for (int i = 0; i < l; i++) {
        if (s[i] == '(') {
            if (level > 0) {
                p += s[i];
            }
            level++;
            st.push(s[i]);
        } else if (s[i] == ')') {
            level--;
            if (level > 0) {
                p += s[i];
            }
            st.pop();
        }
    }
    return p;
}
int main(){
    string s = "(()())(())";
    cout << removeOuterParentheses(s);
}