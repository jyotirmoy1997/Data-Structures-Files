/* Given an infinite supply of each denomination of
 Indian currency { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 }
 and a target value N. Find the minimum number of coins and/or 
 notes needed to make the change for Rs N. You must return the 
 list containing the value of coins required. 
 
 Note => Here, a Dynamic Programming Solution is simply not required because the
 coins denominations are of canonical form - https://pcs.cs.cloud.vt.edu/problems/277 / https://g.co/bard/share/b7a0b89989ed

 */

#include<bits/stdc++.h>
using namespace std;
vector<int> minPartition(int N){
    vector<int> denominations = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
    vector<int> res;
    int i = denominations.size()-1, rem = N;
    while(i >= 0){
        if(rem == 0)
            break;
            
        if(denominations[i] <= rem){
            res.push_back(denominations[i]);
            rem -= denominations[i];
            continue;
        }
        i--;
    }
    return res;
}
int main(){
    int amount = 43;
    auto res = minPartition(amount);
    for(auto it : res)
        cout << it << " ";
}