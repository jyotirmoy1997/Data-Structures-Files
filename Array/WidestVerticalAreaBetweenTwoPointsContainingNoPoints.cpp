#include<bits/stdc++.h>
using namespace std;
int maxWidthOfVerticalArea(vector<vector<int>>& points){
    sort(points.begin(), points.end());
    int maxi = -1e9, n = points.size();
    for(int i=0; i<n-1; i++)
        maxi = max(maxi, points[i+1][0] - points[i][0]);

    return maxi;
}
int main(){
    vector<vector<int>> points = {{8,7},{9,9},{7,4},{9,7}};
    cout << maxWidthOfVerticalArea(points);
}