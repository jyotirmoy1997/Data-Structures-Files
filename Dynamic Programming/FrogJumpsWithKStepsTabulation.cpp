#include<bits/stdc++.h>
using namespace std;
int frogJumpKStepsTabulation(int n, int cost[], int k){
    vector<int> vec(n+1, 0);
    vec[0] = 0;
    for(int i=1; i<=n; i++){
        int min_res = INT_MAX;
        for(int j=1; j<=k; j++)
        {
            if(i - j >= 0)
            {
                int jump = vec[i-j] + abs(cost[i] - cost[i-j]);
                min_res = min(min_res, jump);
            }
        }
        vec[i] = min_res;
    }
    return vec[n];
}
int main(){
    int cost[] = {30, 10, 60, 10, 60, 50};
    cout << frogJumpKStepsTabulation(sizeof(cost)/sizeof(int)-1, cost, 3);
}