/*There are n stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. 
Count the number of ways, the person can reach the top.*/

#include<bits/stdc++.h>
using namespace std;
int climbingStairsRecursion(int n){
    if(n <= 1)
        return n;
    int left = climbingStairsRecursion(n-1);
    int right = climbingStairsRecursion(n-2);
    return left + right;
}
int main(){
    cout << climbingStairsRecursion(6);
}