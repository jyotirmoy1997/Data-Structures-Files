#include<bits/stdc++.h>
using namespace std;
vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    priority_queue<pair<int, string>> pq;
    int n = names.size();
    for(int i=0; i<n; i++)
        pq.push({heights[i], names[i]});
    
    vector<string> res;
    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();
        res.push_back(node.second);
    }

    return res;
}
int main(){
   vector<string> names = {"Mary","John","Emma"};
   vector<int> heights = {180,165,170};
   auto res = sortPeople(names, heights);
   for(auto it : res)
    cout << it << " ";
}