#include<bits/stdc++.h>
using namespace std;
bool isValid(string exp)
{
    stack<char> st;
    for(int i=0; i<exp.length(); i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            st.push(exp[i]);
        }
        else
        {
            if(!st.empty())
            {
                char top = st.top();
                if(top == '(' && exp[i] == ')' || 
                   top == '{' && exp[i] == '}' ||
                   top == '[' && exp[i] == ']')
                   {
                    st.pop();
                   }
                   else
                   {
                    return false;
                   }
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}
int main()
{
    string expression = "[][]{())";
    cout << isValid(expression);
}