#include<bits/stdc++.h>
using namespace std;
int minCost(string &s)
{
    stack<char> st;
    if(s.length() % 2 != 0){
        return -1;
    }
    for(auto ch : s)
    {
        if(ch == '(')
            st.push(ch);
        else
        {
            if(!st.empty() && st.top() == '('){
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }
    int a = 0, b=0;
    while(!st.empty()){
        char ch = st.top();
        st.pop();
        if(ch == '('){
            a++;
        }
        else if(ch == ')'){
            b++;
        }
    }
    return ((a+1)/2) + ((b+1)/2);
}
int main()
{
    string exp = "((((()((";
    cout << minCost(exp);
}