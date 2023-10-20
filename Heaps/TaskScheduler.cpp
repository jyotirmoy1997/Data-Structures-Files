#include<bits/stdc++.h>
using namespace std;
int leastInterval(vector<char>& tasks, int n){
    unordered_map<char, int> mpp;
    for(auto it : tasks)
        mpp[it] += 1;
    
    priority_queue<int> pq;
    for(auto it : mpp)
        pq.push(it.second);
    
    queue<pair<int, int>> q;
    int time = 0;
    while(!q.empty() || !pq.empty()){
        time++;
        if(!pq.empty()){
            if(pq.top() - 1 != 0)
                q.push({pq.top() - 1, time + n});

            pq.pop();
        }
        if(!q.empty() && q.front().second == time){
            pq.push({q.front().first});
            q.pop();
        }
    }
    return time;
}
int main(){
    vector<char> tasks = {'A','A','A','B','B','B'};
    cout << leastInterval(tasks, 2);
}