#include<bits/stdc++.h>
using namespace std;
int evaluate(int n1, int n2, string &op){
    if(op == "+")
        return n1 + n2;
    
    else if(op == "-")
        return n1 - n2;

    else if(op == "*")
        return n1 * n2;
    
    else if(op == "/")
        return n1 / n2;
    
    return -1;
}
int evalRPN(vector<string>& tokens){
    stack<int> st;
    for(auto it : tokens){
        if(it == "+" || it == "-" || it == "*" || it == "/"){
            int n1 = st.top();
            st.pop();
            int n2 = st.top();
            st.pop();
            st.push(evaluate(n2, n1, it));
        }
        else
            st.push(stoi(it));
    }
    return st.top();
}
int main(){
    vector<string> tokens = {"4","13","5","/","+"};
    cout << evalRPN(tokens);
}