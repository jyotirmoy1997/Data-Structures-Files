/*There are n stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. 
Count the number of ways, the person can reach the top.*/

#include<bits/stdc++.h>
using namespace std;
int climbingStairsTabulation(int n)
{
    vector<int> vec(n+1, -1);
    vec[0] = 0;
    vec[1] = 1;
    for(int i=2; i<=n; i++){
        vec[i] = vec[i-1] + vec[i-2];
    }
    return vec[n];
}
int main(){
    cout << climbingStairsTabulation(6);
}