#include<bits/stdc++.h>
using namespace std;
int ladderLength(string beginWord, string endWord, vector<string> &wordList){
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    st.erase(beginWord);
    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        if(word == endWord)
            return steps;
        q.pop();
        for(int i=0; i<word.length(); i++){
            char original = word[i];
            for(char ch='a'; ch <= 'z'; ch++){
                word[i] = ch;
                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}
int main(){
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << ladderLength("hit", "cog", wordList);
}