#include<bits/stdc++.h>
using namespace std;
string reverseString(string s)
{
    stack<char> st;
    for(int i=0; i<s.length(); i++)
    {
        st.push(s[i]);
    }
    string res = "";
    while(!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
    return res;
}
int main()
{
    string str = "Kalashnikov";
    auto res = reverseString(str);
    cout << res;
}