#include<bits/stdc++.h>
using namespace std;
int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    priority_queue<int> pq;
    int n = heights.size();
    for(int i=0; i<n; i++){
        int diff = heights[i+1] - heights[i];
        if(diff <= 0)
            continue;
        
        bricks -= diff;
        pq.push(diff);
        if(bricks < 0){
            if(ladders == 0)
                return i;

            ladders--;
            bricks += pq.top();
            pq.pop();
        }
    }
    return n-1;
}
int main(){
    vector<int> heights = {4,12,2,7,3,18,20,3,19};
    int bricks = 10, ladders = 2;
    cout << furthestBuilding(heights, bricks, ladders);
}