#include <bits/stdc++.h>
using namespace std;
string customSortString(string order, string s) {
    string s1, s2;
    vector<int> freq(26, 0);
    for(auto it : order)
        freq[it - 'a']++;

    for(auto it : s){
        if(freq[it - 'a'] == 0)
            s2 += it;
        
        else
            freq[it - 'a']++;
    }
    for(auto it : order){
        while(freq[it - 'a'] > 1){
            s1 += it;
            freq[it - 'a']--;
        }
    }
    return s1 + s2;
}
int main(){
    string order = "cba", s = "abcd";
    cout << customSortString(order, s);
}