#include<bits/stdc++.h>
using namespace std;
int minSteps(string s, string t){
    unordered_map<char, int> freq1;
    unordered_map<char, int> freq2;
    for(auto it : s)
        freq1[it]++;

    for(auto it : t)
        freq2[it]++;

    int minSteps = 0;
    for(auto it : freq2){
        if(freq1.find(it.first) == freq1.end())
            minSteps += it.second;

        else{
            if(freq1[it.first] < freq2[it.first])
                minSteps += freq2[it.first] - freq1[it.first];
        }
    }
    return minSteps;
}
int main(){
    string s = "leetcode", t = "practice";
    cout << minSteps(s, t);
}