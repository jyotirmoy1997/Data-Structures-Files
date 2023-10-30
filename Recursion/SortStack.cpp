#include<bits/stdc++.h>
using namespace std;
void insertSorted(stack<int> &st, int d){
    if(st.empty() || st.top() <= d){
        st.push(d);
        return;
    }
    int n = st.top();
    st.pop();
    insertSorted(st, d);
    st.push(n);
}
void sortStack(stack<int> &st){
    if(st.empty())
        return;
    
    int n = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, n);
}
int main(){
    stack<int> st;
    st.push(6);
    st.push(4);
    st.push(1);
    st.push(7);
    st.push(12);
    sortStack(st);
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}