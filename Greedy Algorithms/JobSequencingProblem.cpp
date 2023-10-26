#include<bits/stdc++.h>
using namespace std;
bool comp(vector<int> &a, vector<int> &b){
    return a[2] > b[2];
}
vector<int> jobScheduling(vector<vector<int>> &jobs){
    sort(jobs.begin(), jobs.end(), comp);

    int deadline = 0;
    for(auto x: jobs) 
        deadline = max(deadline, x[2]);

    vector<bool> visit(deadline, false);
    int countJobs = 0;
    int maxProfit = 0;

    for(auto x: jobs){
        int deadline = x[1];
        int profit = x[2];
        int j = deadline - 1; 
        while(j >= 0){
            if(visit[j] == false){
                countJobs++;
                maxProfit += profit;
                visit[j] = true;
                break;
            }
            j--;
        }
    }
    return {countJobs, maxProfit};
}
int main(){
    vector<vector<int>> jobs = {{1,4,20},
                                {2,1,10},
                                {3,1,40},
                                {4,1,30}};

    auto res = jobScheduling(jobs);
    cout << res[0] << "-" << res[1];
}