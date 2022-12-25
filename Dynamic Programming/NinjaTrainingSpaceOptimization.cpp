#include<bits/stdc++.h>
using namespace std;
int ninjaTraining(vector<vector<int>> &points){
    vector<int> prev(4, 0);

    // Base Cases
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day=1; day<points.size(); day++)
    {
        vector<int> temp(4, 0);
        for(int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for(int task = 0; task < 3; task++)
            {
                temp[last] = max(temp[last], points[day][task] + prev[task]);
            }
        }
        prev = temp;
    }
    return prev[3];
}
int main(){
    vector<vector<int>> points{
        {2, 1, 3},
        {3, 4, 6},
        {10, 1, 6}
    };
    cout << ninjaTraining(points);
}