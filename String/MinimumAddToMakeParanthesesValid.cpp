#include <bits/stdc++.h>
using namespace std;
int minAddToMakeValid(string s){
    stack<char> st;
    int l = s.length(), count = 0;
    for(int i=0; i<l; i++){
        if(s[i] == '(')
            st.push(s[i]);

        else if(s[i] == ')'){
            if(!st.empty())
                st.pop();
            
            else
                count++;
        }
    }
    while(!st.empty()){
        st.pop();
        count++;
    }
    return count;
}
int main() {
    string s = "()))";
    cout << minAddToMakeValid(s);
    return 0;
}
