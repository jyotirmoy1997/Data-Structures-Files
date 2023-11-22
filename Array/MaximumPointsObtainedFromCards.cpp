#include<bits/stdc++.h>
using namespace std;
int maxScore(vector<int> &cardPoints, int k){
    long long preSum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
    long long sum = 0, maxSum;
    int n = cardPoints.size(), right = 0, left = 0;
    while(right < n-k){
        sum += cardPoints[right];
        right++;
    }
    maxSum = preSum - sum;
    while(right < n){
        sum += cardPoints[right] - cardPoints[left];
        left++;
        right++;
        maxSum = max(maxSum, preSum - sum);
    }
    return maxSum;
}
int main(){
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    cout << maxScore(cardPoints, 3);
}