#include<bits/stdc++.h>
using namespace std;
void insertAtLast(stack<int> &st, int d){
    if(st.empty()){
        st.push(d);
        return;
    }
    int n = st.top();
    st.pop();
    insertAtLast(st, d);
    st.push(n);
}
void reverseStack(stack<int> &st){
    if(st.empty())
        return;
    
    int n = st.top();
    st.pop();
    reverseStack(st);
    insertAtLast(st, n);
}
int main(){
    stack<int> st;
    st.push(6);
    st.push(4);
    st.push(1);
    st.push(7);
    st.push(12);
    reverseStack(st);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}