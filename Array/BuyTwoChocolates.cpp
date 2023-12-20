#include<bits/stdc++.h>
using namespace std;
int buyChoco(vector<int>& prices, int money){
    int smallest = prices[0], second_smallest = 1e9, n = prices.size();
    for(int i=1; i<n; i++){
        if(prices[i] < smallest){
            second_smallest = smallest;
            smallest = prices[i];
        }
        else if(prices[i] >= smallest && prices[i] < second_smallest)
            second_smallest = prices[i];
    }
    return (money - smallest - second_smallest < 0) ? money : money - smallest - second_smallest;
}
int main(){
    vector<int> prices = {3, 2, 3};
    int money = 3;
    cout << buyChoco(prices, money);
}