#include<bits/stdc++.h>
using namespace std;
int func(int day, int last, vector<vector<int>> &arr)
{
    if(day == 0)
    {
        int maximum = 0;
        for(int task=0; task<3; task++){
            if(task != last){
                maximum = max(maximum, arr[0][task]);
            }
        }
        return maximum;
    }
    int maximum = 0;
    for(int task=0; task <3; task++){
        if(task != last){
            int point = arr[day][task] + func(day-1, task, arr);
            maximum = max(point, maximum);
        }
    }
    return maximum;
}
int main(){
    vector<vector<int>> vec{
        {2, 1, 3},
        {3, 4, 6},
        {10, 1, 6}
    };
    cout << func(vec.size()-1, 3, vec);
}