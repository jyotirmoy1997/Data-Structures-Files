#include<bits/stdc++.h>
using namespace std;
int countCharacters(vector<string>& words, string chars) {
    unordered_map<char, int> dict;
    for(auto it : chars)
        dict[it]++;

    int n = words.size(), res = 0;
    for(int i=0; i<n; i++){
        string s = words[i];
        int len = s.length(), c = 0;
        unordered_map<char, int> mpp = dict;
        for(int j=0; j<len; j++){
            if(mpp.find(s[j]) != mpp.end() && mpp[s[j]] > 0)
                c++;

            mpp[s[j]]--;
        }
        if(c == len)
            res += len;
    }
    return res;
}
int main(){
    vector<string> words = {"cat","bt","hat","tree"};
    string chars = "atach";
    cout << countCharacters(words, chars);
}