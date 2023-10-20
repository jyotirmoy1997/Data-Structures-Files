#include<bits/stdc++.h>
using namespace std;
bool lemonadeChange(vector<int> &bills){
    vector<int> denom(3, 0);
    int five = 0, ten = 0, twenty = 0, change = 0, n = bills.size();
    for(int i=0; i<n; i++){
        int rem = bills[i] - 5;
        if(change < rem)
            return false;

        else{
            change -= rem;
            change += bills[i];
            int index = 2;
            while(index >= 0){
                
            }
        }
        if(bills[i] == 5)
            denom[0]++;
        else if(bills[i] == 10)
            denom[1]++;
        else if(bills[i] == 20)
            denom[2]++;
    }
    return true;
}
int main(){
    vector<int> bills = {5, 5, 5, 10, 20};
}