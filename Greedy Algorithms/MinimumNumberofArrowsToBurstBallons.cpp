/* Solution => https://youtu.be/fvBhjAp0j9c?si=G89kOO52-0Ar-uye */

#include<bits/stdc++.h>
using namespace std;
bool comp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), comp);
    int arrows = 1, last = points[0][1], n = points.size();
    for(int i=1; i<n; i++){
        if(points[i][0] > last){
            arrows++;
            last = points[i][1];
        }
    }
    return arrows;
}
int main(){
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    cout << findMinArrowShots(points);
}