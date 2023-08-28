#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mergeOverlappingIntervalsBrute(vector<vector<int>> &arr){
    // Approach => First Sort the array and then Check From the Next Element
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        int start = arr[i][0];
        int end = arr[i][1];
        if(!ans.empty() && end <= ans.back()[1])
            continue;

        for(int j=i+1; j<n; j++){
            if(arr[j][0] <= end){
                end = max(end, arr[j][1]);
            }
            else
                break;
        }
        ans.push_back({start, end});
    }
    return ans;
}
vector<vector<int>> mergeOverlappingIntervalsOptimal(vector<vector<int>> &arr){
    // Approach => First Sort the array and then Check From the Next Element
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
            continue;
    }
    return ans;
}
int main(){
    vector<vector<int>> vec = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    auto ans = mergeOverlappingIntervalsOptimal(vec);
    for(auto it : ans){
        for(auto el : it)
            cout << el << " ";
        
        cout << endl;
    }
}