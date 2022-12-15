/*There are n stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. 
Count the number of ways, the person can reach the top.*/


#include<bits/stdc++.h>
using namespace std;
int climbingStairsRecursion(int n, vector<int> &vec)
{
    if(n <= 1)
        return n;
    if(vec[n] != -1)
        return vec[n];
    int left = climbingStairsRecursion(n-1, vec);
    int right = climbingStairsRecursion(n-2, vec);
    vec[n] = left + right;
    return vec[n];
}
int main(){
    vector<int> vec(8, -1);
    cout << climbingStairsRecursion(6, vec);
}