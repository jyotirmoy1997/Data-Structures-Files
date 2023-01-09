/*A thief wants to rob a store. He is carrying a bag of capacity W. 
The store has ‘n’ items. Its weight is given by the ‘wt’ array and 
its value by the ‘val’ array. He can either include an item in its 
knapsack or exclude it but can’t partially have it as a fraction. 
We need to find the maximum value of items that the thief can steal.

Approach :: https://takeuforward.org/data-structure/0-1-knapsack-dp-19/

*/

#include<bits/stdc++.h>
using namespace std;
int func(int index, int W, vector<int> &wt, vector<int> &val){
    if(index == 0){
        if(wt[0] <= W)
            return val[0];
        return 0;
    }
    int notTake = 0 + func(index-1, W, wt, val);
    int take = INT_MIN;
    if(W >= wt[index])
        take = val[index] + func(index-1, W-wt[index], wt, val);
    
    return max(take, notTake);
}
int knapSack(vector<int> &wt, vector<int> &val, int n, int maxWeight){
    return func(n-1, maxWeight, wt, val);
}
int main(){
    vector<int> wt = {3, 4, 5};
    vector<int> val = {30, 50, 60};
    int maxWeight = 8;
    int n = wt.size();
    cout << knapSack(wt, val, n, maxWeight);
}