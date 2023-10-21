/* This is a variation of the activity selection problem*/

#include<bits/stdc++.h>
using namespace std;
int maxMeetings(vector<int> &start, vector<int> &end, int n){
    vector<pair<int, int>> meetings;
    for(int i=0; i<n; i++){
        meetings.push_back({end[i], start[i]});
    }
    sort(meetings.begin(), meetings.end());
    int count = 1, prev = meetings[0].first;
    for(int i=1; i<n; i++){
        if(meetings[i].second > prev){
            count++;
            prev = meetings[i].first;
        }
    }
    return count;
}
int main(){
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end =  {2,4,6,7,9,9};
    int n = start.size();
    cout << maxMeetings(start, end, n);
}