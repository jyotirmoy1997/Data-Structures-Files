#include<bits/stdc++.h>
using namespace std;
void rec(vector<string> &ans, string s, int index, int n){
    if(index == n){
        ans.push_back(s);
        return;
    }

    // 0s
    rec(ans, s + "0", index + 1, n);

    // 1s
    if(index == 0 || s[index-1] != '1')
        rec(ans, s + "1", index + 1, n);
}
vector<string> generateString(int N) {
    vector<string> ans;
    int index = 0;
    string s = "";
    rec(ans, s, index, N);
    return ans;
}
int main(){
    auto res = generateString(3);
    for(auto it : res)
        cout << it << " ";
}