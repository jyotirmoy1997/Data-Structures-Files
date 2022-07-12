#include<bits/stdc++.h>
using namespace std;
int evaluate(char op, int t1, int t2)
{
        // + => 43
        // - => 45
        // / => 47
        // * => 42
        // ^ => 94
        int val;
        if((int)op == 43) // Addition
        {
            val = t1 + t2;
        }
        else if((int)op == 45) // Subtraction
        {
            val = t1 - t2;
        }
        else if((int)op == 47) // Subtraction
        {
            val = t1 / t2;
        }
        else if((int)op == 42) // Subtraction
        {
            val = t1 * t2;
        }
        else if((int)op == 94) // Subtraction
        {
            val = (int)pow(t1, t2);
        }
        return val;
}
int postfixEvaluator(string expression)
{
    stack<int> st;
    for(auto it: expression)
    {
        // cout << it << " ";
        if(it >= '0' && it <= '9')
        {
            st.push((int)it - 48);
        }
        else
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            int c = evaluate(it, b, a);
            st.push(c);
            // cout << a << "-" << b << "-" << c << " ";
        }
        // cout << st.top() << endl;
    }
    int res = st.top();
    st.pop();
    return res;
}
int main()
{
    string expression = "43^1^52^1^*";
    cout << postfixEvaluator(expression);

    // cout << (int)'4' - 48;
}