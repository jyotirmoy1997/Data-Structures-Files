#include<bits/stdc++.h>
using namespace std;
void rec(stack<int> &st, int data)
{
    if(st.empty())
    {
        st.push(data);
        return;
    }
    int num = st.top();
    st.pop();
    rec(st, data);
    st.push(num);
}
void insertAtLast(stack<int> &st, int data)
{
    rec(st, data);
}
void reverseStack(stack<int> &st)
{
    if(st.empty())
        return;
    int num = st.top();
    st.pop();
    reverseStack(st);
    insertAtLast(st, num);
}
int main()
{
    stack<int> st;
    st.push(6);
    st.push(4);
    st.push(1);
    st.push(7);
    st.push(12);
    reverseStack(st);
    // insertAtLast(st, 78);
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}