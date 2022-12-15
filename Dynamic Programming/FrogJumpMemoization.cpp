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

*/

#include<bits/stdc++.h>
using namespace std;
int frogJumpRecursion(int n, int cost[], vector<int> &vec){
    int left = INT_MAX, right = INT_MAX;
    if(n == 0)
        return 0;

    if(vec[n] != -1)
        return vec[n];

    left = frogJumpRecursion(n-1, cost, vec) + abs(cost[n] - cost[n-1]);
    if(n > 1){
        right = frogJumpRecursion(n-2, cost, vec) + abs(cost[n] - cost[n-2]);
    }
    return vec[n] = min(left, right);
}
int main(){
    int cost[] = {30, 10, 60, 10, 60, 50};
    vector<int> vec(sizeof(cost)/sizeof(int)+1, -1);
    cout << frogJumpRecursion(sizeof(cost)/sizeof(int) - 1, cost, vec);
}