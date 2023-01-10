#include<bits/stdc++.h>
using namespace std;
int func(int index, int N, vector<int> &price){
    if(index == 0)
        return N * price[0];
    
    int notTake = 0 + func(index-1, N, price);
    int take = INT_MIN;
    int rodLength = index + 1;
    if(rodLength <= N)
        take = price[index] + func(index, N-rodLength, price);
    
    return max(take, notTake);
}
int cutRods(vector<int> &price, int N){
    int n = N-1;
    return func(n, N, price);
}
int main(){
    vector<int> price = {2, 5, 7, 8, 10};
    int N = price.size();
    cout << cutRods(price, N);
}