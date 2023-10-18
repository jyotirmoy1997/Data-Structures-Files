#include<bits/stdc++.h>
using namespace std;
vector<int> replaceWithRank(vector<int> &arr, int n) {
    vector<int> ans(n);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    for(int i=0;i<n;i++)
        pq.push({arr[i],i});

    int rank=0;
    int lastEle=INT_MIN;
    while(pq.size()){
        auto node = pq.top();
        if(node.first != lastEle){
            rank++;
            lastEle = node.first;
        }
        ans[node.second] = rank;  
        pq.pop();
    }

    return ans;
}
int main(){
    vector<int> arr = {1, 2, 6, 9, 2};
    auto res = replaceWithRank(arr, arr.size());
    for(auto it : res)
        cout << it << " ";
}