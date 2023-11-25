#include<bits/stdc++.h>
using namespace std;
int canCompleteCircuit(vector<int> &gas, vector<int> &cost){
    int gasSum = accumulate(gas.begin(), gas.end(), 0);
    int costSum = accumulate(cost.begin(), cost.end(), 0);

    if(gasSum < costSum)
        return -1;

    int total = 0, result = 0, n = gas.size();;
    for(int i=0; i<n; i++){
        total += gas[i] - cost[i];
        if(total < 0){
            total = 0;
            result = i + 1;
        }
    }
    return result;
}
int main(){
    vector<int> gas = {2, 3, 4};
    vector<int> cost = {3, 4, 3};
    cout << canCompleteCircuit(gas, cost);
}