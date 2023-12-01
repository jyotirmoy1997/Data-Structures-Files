/* Solution => https://leetcode.com/problems/word-pattern/solutions/2977910/c-hashmap-easy-to-understand/?envType=study-plan-v2&envId=top-interview-150*/

#include <bits/stdc++.h>
using namespace std;
bool wordPattern(string pattern, string s){
    unordered_map<char, string>chToWordMap;
    unordered_map<string, char>wordToChMap;
    s.push_back(' ');
    string currWord = "";
    int chIdx = 0;
    for (int  i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            char currCh = pattern[chIdx++];
            if (chToWordMap.count(currCh)){
                string alreadyMappedWord = chToWordMap[currCh];
                if (alreadyMappedWord != currWord) return false;
            }
            else if (wordToChMap.count(currWord)){
                char alreadyMappedCh = wordToChMap[currWord];
                if (alreadyMappedCh != currCh) return false;
            }
            else{
                chToWordMap[currCh] = currWord;
                wordToChMap[currWord] = currCh;
            }
            currWord = "";
        }
        else 
            currWord.push_back(s[i]);
    }
    return (chIdx == pattern.size());
}
int main(){
    string pattern = "jquery";
    string s = "jquery";
    cout << wordPattern(pattern, s);
}