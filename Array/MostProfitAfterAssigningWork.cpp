#include<bits/stdc++.h>
using namespace std;
int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    // Create a vector of pairs to combine difficulty and profit together
    vector<pair<int, int>> jobs;
    int n = difficulty.size();
    for(int i = 0; i < n; ++i) {
        jobs.push_back({difficulty[i], profit[i]});
    }
    
    // Sort jobs based on difficulty
    sort(jobs.begin(), jobs.end());
    
    // Sort workers based on their ability
    sort(worker.begin(), worker.end());
    
    int maxProfit = 0, best = 0, j = 0;
    
    // Iterate through each worker
    for(int i = 0; i < worker.size(); ++i) {
        // Update the best profit the worker can get
        while(j < n && jobs[j].first <= worker[i]) {
            best = max(best, jobs[j].second);
            j++;
        }
        // Add the best profit to the total profit
        maxProfit += best;
    }
    
    return maxProfit;
}
int main(){
    vector<int> difficulty = {2,4,6,8,10}, profit = {10,20,30,40,50}, worker = {4,5,6,7};
    cout << maxProfitAssignment(difficulty, profit, worker);
}