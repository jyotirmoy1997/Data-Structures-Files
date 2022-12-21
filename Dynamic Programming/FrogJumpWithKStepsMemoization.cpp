#include<bits/stdc++.h>
using namespace std;
int frogJumpKStepsRecursion(int n, int cost[], int k, vector<int> &vec){
    if(n == 0)
        return 0;

    int min_res = INT_MAX;
    int res = INT_MAX;

    if(vec[n] != -1)
        return vec[n];

    for(int i=1; i<k; i++){
        if(n - i >= 0){
            res = frogJumpKStepsRecursion(n - i, cost, k, vec) + abs(cost[n] - cost[n-i]);
        }
        min_res = min(min_res, res);
        vec[n] = min_res;
    }
    return vec[n];
}
int main()
{
    int cost[] = {30, 10, 60, 10, 60, 50};
    vector<int> vec(sizeof(cost)/sizeof(int), -1);
    cout << frogJumpKStepsRecursion(sizeof(cost)/sizeof(int)-1, cost, 3, vec);
}