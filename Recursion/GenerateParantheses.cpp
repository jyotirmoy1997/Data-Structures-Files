#include<bits/stdc++.h>
using namespace std;
void rec(vector<string> &ans, int index, int n, string s, int open, int close) {
    if (index == 2 * n) {
        ans.push_back(s);
        return;
    }
    if (open < n) 
        rec(ans, index + 1, n, s + "(", open + 1, close);

    if (close < open)
        rec(ans, index + 1, n, s + ")", open, close + 1);
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    int index = 0;
    string s = "";
    int open = 0;
    int close = 0;
    rec(ans, index, n, s, open, close);
    return ans;
}
int main(){
    auto res = generateParenthesis(3);
    for(auto it : res)
        cout << it << " ";
}