/* The Idea is to compare all strings one by one. 
Step 1:
    Find the minimum length of all the Strings. Takes O(M) time where M is the total no. of strings
Step 2:
    Keep the first string as pattern and then match the rest of the strings

Overall Time Complexity : O(M x N)

 */

#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string> &strs){
    int mini = INT_MAX;
    for(auto it : strs){
        int size = it.length();
        mini = min(mini, size);
    }

    int totStrings = strs.size();
    string pattern = strs[0];
    string ans = "";

    for(int i=0; i<mini; i++){
        for(int j=1; j<totStrings; j++){
            string s = strs[j];
            if(s[i] != pattern[i])
                return ans;
        }
        ans += pattern[i];
    }
    return ans;
}
int main(){
    vector<string> strs = {"flower","flow","flight"};
    cout << longestCommonPrefix(strs);
}