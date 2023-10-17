// https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include<bits/stdc++.h>
using namespace std;
int kthLargest(vector<int> &arr,int N,int K){
    priority_queue<int> pq;
    for(int i=0; i<N; i++){
        int sum = 0;
        for(int j=i; j<N; j++){
            sum += arr[j];
            pq.push(sum);
        }
    }
    int c = 0;
    while(c < K-1){
        pq.pop();
        c++;
    }
    return pq.top();
}
int main(){
    vector<int> arr = {2,6,4,1};
    cout << kthLargest(arr, arr.size(), 3);
}