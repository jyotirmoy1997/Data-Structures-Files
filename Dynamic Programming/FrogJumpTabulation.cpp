/*There is a frog on the '1st' step of an 'N' stairs long staircase. 
The frog wants to reach the 'Nth' stair. 
'HEIGHT[i]' is the height of the '(i+1)th' stair.
If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute 
value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase, he can jump 
either to '(i+1)th' stair or to '(i+2)th' stair. Your task is to find the minimum total 
energy used by the frog to reach from '1st' stair to 'Nth' stair.

Approach 1 :: Here, we are starting from the last index and counting the cost
of two cases => i) if the frog jumps 1 step
                ii) if the frog jumps 2 steps

Then we are taking the minimum of the two.

Approach 2 :: Using a vector to store the intermediate results of overlapping sub problems

Approach 3 :: Converting the Recursion to tabulation 

*/

#include<bits/stdc++.h>
using namespace std;
int frogJumpRecursion(int n, int cost[]){
    vector<int> vec(n+1, 0);
    vec[0] = 0;
    for(int i=1; i<=n; i++){
        int left = vec[i-1] + abs(cost[i] - cost[i-1]);
        int right = INT_MAX;
        if(i > 1)
            right = vec[i-2] + abs(cost[i] - cost[i-2]);

        vec[i] = min(left, right);
    }
    return vec[n];
}
int main(){
    int cost[] = {30, 10, 60, 10, 60, 50};
    cout << frogJumpRecursion(sizeof(cost)/sizeof(int) - 1, cost);
}