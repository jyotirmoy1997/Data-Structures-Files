#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> activities(int f[], int s[], int n){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i=0; i<n; i++){
        pq.push(make_pair(s[i], f[i]));
    }
    auto firstPair = pq.top();
    pq.pop();
    int start = firstPair.second;
    int end = firstPair.first;
    vector<pair<int, int>> result;
    result.push_back(make_pair(start, end));
    while(!pq.empty()){
        auto it = pq.top();
        if(end <= it.second){
            start = it.second;
            end = it.first;
            result.push_back(make_pair(start, end));
        }
        pq.pop();
    }
    return result;
}
int main(){
    int f[] = {1, 4, 12, 15, 7};
    int s[] = {13, 6, 14, 19, 13};
    vector<pair<int, int>> res = activities(f, s, sizeof(f)/sizeof(int));
    cout << "The activities are :: " << endl;
    for(auto it : res){
        cout << it.first << "-" << it.second << endl;
    }
}