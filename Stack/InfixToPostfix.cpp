#include<bits/stdc++.h>
using namespace std;
void infixtoPostfix(string expression)
{
    unordered_map<char, int> prec;
    prec.insert({'^', 3});
    prec.insert({'*', 2});
    prec.insert({'/', 2});
    prec.insert({'+', 1});
    prec.insert({'-', 1});
    prec.insert({'(', 0});

    stack<char> st;
    expression += ")";
    st.push('(');

    //cout << expression;

    string postfix = "";
    for(auto it: expression)
    {
        if(it == '(')
        {
            st.push(it);
        }
        else if(it >= 'a' && it <= 'z')
        {
            postfix += it;
        }
        else if(it == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while(!st.empty() && prec.at(st.top()) >= prec.at(it))
            {
                //cout << st.top();
                postfix += st.top();
                st.pop();
            }
            st.push(it);
        }
    }

    cout << postfix;
}
int main()
{
    string expression = "a+b^c*e+d^f";
    infixtoPostfix(expression);
}