#include<bits/stdc++.h>
using namespace std;
int candy(vector<int> &ratings){
    int n = ratings.size();
    vector<int> candies(n, 1);

    // First Pass
    for(int i=1; i<n; i++){
        if(ratings[i-1] < ratings[i])
            candies[i] = candies[i-1] + 1;
    }

    // Second Pass
    for(int i=n-2; i>=0; i--){
        if(ratings[i] > ratings[i+1])
            candies[i] = max(candies[i], candies[i+1] + 1);
    }

    int totalCandies = accumulate(candies.begin(), candies.end(), 0);
    return totalCandies;
}
int main(){
    vector<int> ratings = {1,2,2};
    cout << candy(ratings);
}