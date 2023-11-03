#include<bits/stdc++.h>
using namespace std;
void evaluate(string num, int target, int index, vector<string> &res, string s, long long currentVal, long long prevVal) {
    if (index == num.size()) {
        if (currentVal == target) {
            res.push_back(s);
        }
        return;
    }

    for (int i = 1; i <= num.size() - index; i++) {
        string currentNumStr = num.substr(index, i);
        // Avoid numbers with leading zeros.
        if (currentNumStr.size() > 1 && currentNumStr[0] == '0')
            continue;

        long long currentNum = stoll(currentNumStr);

        if (s.empty()) {
            evaluate(num, target, index + i, res, currentNumStr, currentNum, currentNum);
        } else {
            evaluate(num, target, index + i, res, s + "+" + currentNumStr, currentVal + currentNum, currentNum);
            evaluate(num, target, index + i, res, s + "-" + currentNumStr, currentVal - currentNum, -currentNum);
            evaluate(num, target, index + i, res, s + "*" + currentNumStr, currentVal - prevVal + (prevVal * currentNum), prevVal * currentNum);
        }
    }
}

vector<string> addOperators(string num, int target) {
    vector<string> res;
    if (num.empty()) return res;
    
    evaluate(num, target, 0, res, "", 0, 0);
    return res;
}
int main(){
    string num = "123";
    auto res = addOperators(num, 6);
    for(auto it : res)
        cout << it << " ";
}