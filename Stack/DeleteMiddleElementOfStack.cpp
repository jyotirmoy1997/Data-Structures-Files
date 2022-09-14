#include<bits/stdc++.h>
using namespace std;
void rec(stack<int> &st, int count, int size)
{
    if(count == (size)/2)
    {
        st.pop();
        return;
    }
    int num = st.top();
    st.pop();
    rec(st, count+1, size);
    st.push(num);
}
void delMiddleElement(stack<int> &st)
{
    int size = st.size();
    int count = 0;
    rec(st, count, size);
}
int main()
{
    stack<int> st;
    st.push(6);
    st.push(4);
    st.push(1);
    st.push(7);
    st.push(12);
    delMiddleElement(st);
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}