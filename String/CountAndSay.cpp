#include <bits/stdc++.h>
using namespace std;
string countAndSay(int n){
    if(n == 1)
        return "1";

    string s = countAndSay(n-1);
    string ans = "";
    int l = s.length(), counter = 0;
    for(int i=0; i<l; i++){
        counter++;
        if(i == l-1 || s[i] != s[i+1]){
            ans += to_string(counter) + s[i];
            counter = 0;
        }
    }
    return ans; 
}
int main() {
    cout << countAndSay(4);
    return 0;
}