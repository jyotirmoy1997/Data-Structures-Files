/* Approach => The Idea is to store all the frequencies in a map, then store them in a Max Heap.
Finally, retrieve the answer from the max heap*/

#include<bits/stdc++.h>
using namespace std;
string frequencySort(string s){
   unordered_map<char, int> mpp;
   int l = s.length();
   for(int i=0; i<l; i++)
        mpp[s[i]] += 1;
    
    priority_queue<pair<int, char>> pq;
    for(auto it : mpp)
        pq.push({it.second, it.first});

    string ans = "";
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        for(int i=0; i<it.first; i++){
            ans += it.second;
        }
    }
    return ans;
}
int main(){
    string s = "tree";
    cout << frequencySort(s);
}   