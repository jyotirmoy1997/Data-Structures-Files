#include<bits/stdc++.h>
using namespace std;
int kSorted(vector<vector<int>> &arr, int k, int n) {
    priority_queue<pair<int,pair<int, int>>, 
    vector<pair<int,pair<int, int>>>, 
    greater<pair<int,pair<int, int>>>> pq;

    int mini = INT_MAX, maxi = INT_MIN;
    for(int i=0; i<k; i++){
        int element = arr[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        pq.push({element, {i, 0}});
    }

    int start = mini, end = maxi;
    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();

        mini = node.first;
        int row = node.second.first;
        int col = node.second.second;
        if(maxi - mini < end - start){
            mini = start;
            maxi = end;
        }
        if(col < n){
            maxi = max(maxi, arr[row][col+1]);
            pq.push({arr[row][col+1], {row, col+1}});
        }
        else
            break;
    }
    return end - start + 1;
}
int main(){
    
}