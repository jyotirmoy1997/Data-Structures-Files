#include<bits/stdc++.h>
using namespace std;
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList){
    unordered_set<string> st(wordList.begin(), wordList.end());
    vector<vector<string>> ans;
    if(st.count(endWord) == 0)
        return ans;

    queue<vector<string>> q;
    q.push({beginWord});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level = 0;
    while(!q.empty()){
        auto vec = q.front();
        q.pop();
       

        // Erase everything from the set that was used on previous level
        if(vec.size() > level){
            level++;
            for(auto it : usedOnLevel)
                st.erase(it);
        }

        auto word = vec.back();
        // Check if the word is Final Word or not
        if(word == endWord){
            // break;
            if(ans.size() == 0)
                ans.push_back(vec);
            
            else if(ans[0].size() == vec.size())
                ans.push_back(vec);
        }

        // Perform Substitution operation and check
        for(int j=0; j<word.size(); j++){
            char original = word[j];
            for(char ch='a'; ch<='z'; ch++){
                word[j] = ch;
                if(st.count(word) > 0){
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[j] = original;
        }
    }
    return ans;
}
int main(){
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    auto ans = findLadders("hit", "cog", wordList);
    for(auto it : ans){
        for(auto el : it)
            cout << el << "->";
        
        cout << endl;
    }
}