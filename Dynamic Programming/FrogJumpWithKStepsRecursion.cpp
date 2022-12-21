#include<bits/stdc++.h>
using namespace std;
int frogJumpKStepsRecursion(int n, int cost[], int k){
    if(n == 0)
        return 0;
    int min_res = INT_MAX;
    int res = INT_MAX;
    for(int i=1; i<k; i++){
        if(n - i >= 0){
            res = frogJumpKStepsRecursion(n - i, cost, k) + abs(cost[n] - cost[n-i]);
        }
        min_res = min(min_res, res);
    }
    return min_res;
}
int main()
{
    int cost[] = {30, 10, 60, 10, 60, 50};
    cout << frogJumpKStepsRecursion(sizeof(cost)/sizeof(int)-1, cost, 3);
}