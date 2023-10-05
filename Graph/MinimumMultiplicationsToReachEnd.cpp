// TC -> O(100000 * N)

#include<bits/stdc++.h>
using namespace std;
int minMultiplications(vector<int> &arr, int start, int end){
    int MOD = 100000;
    queue<pair<int, int>> q;
    vector<int> dis(100000, INT_MAX);
    dis[start] = 0;
    q.push({start, 0});
    while(!q.empty()){
        auto node = q.front().first;
        auto steps = q.front().second;
        q.pop();
        for(auto it : arr){
            int num = (node * it) % MOD;
            if(steps + 1 < dis[num]){
                dis[num] = steps + 1;
                if(num == end)
                    return steps + 1;

                q.push({num, steps + 1});
            }
            
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {2, 5, 7};
    cout << minMultiplications(arr, 3, 75);
}