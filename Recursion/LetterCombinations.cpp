#include<bits/stdc++.h>
using namespace std;
void rec(string digits, int index, string s, unordered_map<char, vector<char>> mpp, vector<string> &res){
    if(index == digits.size()){
        res.push_back(s);
        return;
    }

    auto vec = mpp[digits[index]];
    for(int i=0; i<vec.size(); i++){
        rec(digits, index + 1, s + vec[i], mpp, res);
    }
}
vector<string> letterCombinations(string digits){
    vector<string> res;
    if(digits.size() == 0)
        return res;

    unordered_map<char, vector<char>> mpp;
    mpp['2'] = {'a', 'b', 'c'};
    mpp['3'] = {'d', 'e', 'f'};
    mpp['4'] = {'g', 'h', 'i'};
    mpp['5'] = {'j', 'k', 'l'};
    mpp['6'] = {'m', 'n', 'o'};
    mpp['7'] = {'p', 'q', 'r', 's'};
    mpp['8'] = {'t', 'u', 'v'};
    mpp['9'] = {'w', 'x', 'y', 'z'};

    string s = "";
    rec(digits, 0, s, mpp, res);
    return res;
}
int main(){
    string digits = "23";
    auto res = letterCombinations(digits);
    for(auto it : res)
        cout << it << " ";
}