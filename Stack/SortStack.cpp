#include<bits/stdc++.h>
using namespace std;
void insertLastSorted(stack<int> &st, int val)
{
    if(st.empty() || st.top() < val)
    {
        st.push(val);
        return;
    }
    int n = st.top();
    st.pop();
    insertLastSorted(st, val);

    st.push(n);

}
void sortStack(stack<int> &st)
{
    if(st.empty())
        return;

    int num = st.top();
    st.pop();
    sortStack(st);
    insertLastSorted(st, num);
}
int main()
{
    stack<int> st;
    st.push(6);
    st.push(4);
    st.push(1);
    st.push(7);
    st.push(12);
    sortStack(st);
    // insertAtLast(st, 78);
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}