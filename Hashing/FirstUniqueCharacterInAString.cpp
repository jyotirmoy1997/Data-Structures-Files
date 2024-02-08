#include<bits/stdc++.h>
using namespace std;
int firstUniqChar(string s) {
    vector<pair<int, int>> freq(26, {0, -1});
    int len = s.length();
    for(int i=0; i<len; i++){
        freq[s[i] - 'a'].first++;
        freq[s[i] - 'a'].second = (freq[s[i] - 'a'].second == -1) ? i : freq[s[i] - 'a'].second;
    }
    int index = 1e9;
    for(auto it : freq){
        if(it.first == 1)
            index = min(index, it.second);
    }
    return (index == 1e9) ? -1 : index;
}
int main(){
    string s = "loveleetcode";
    cout << firstUniqChar(s);
}