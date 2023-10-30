#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
    int n = intervals.size();
    int newStart = newInterval[0];
    int newEnd = newInterval[1];
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        if(intervals[i][0] > newEnd){
            ans.push_back(newInterval);
            copy(intervals.begin() + i, intervals.end(), back_inserter(ans));
            return ans;
        }
        else if(intervals[i][1] < newStart)
            ans.push_back(intervals[i]);

        else{
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
    }
    ans.push_back(newInterval);
    return ans;
}
int main(){
    vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval = {4,8};
    auto res = insert(intervals, newInterval);
    for(auto it : res)
        cout << it[0] << "-" << it[1] << endl;
}