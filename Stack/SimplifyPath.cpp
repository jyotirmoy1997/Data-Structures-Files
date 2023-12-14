#include<bits/stdc++.h>
using namespace std;
string simplifyPath(string path) {
    stack<string> st;
    string curr = "";
    path.push_back('/');
    for(auto ch : path){
        if(ch == '/'){
            if(curr == ".."){
                if(!st.empty())
                    st.pop();
            }
            else if(curr != "" && curr != ".")
                st.push(curr);
            
            curr = "";
        }
        else
            curr += ch;
    }
    string res = "";
    while(!st.empty()){
        res = '/' + st.top() + res;
        st.pop();
    }
    return (res == "") ? "/" : res;
}
int main(){

}