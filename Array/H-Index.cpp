/* This problem is a variation of the counting sort.

    1. Since, we can only have n papers, the papers which have more than n citations can not be the answer.
     The idea behind it is some bucket sort mechanisms. The h-index is defined as the number of papers with
     reference greater than the number. So assume n is the total number of papers, if we have n+1 buckets, 
     number from 0 to n, then for any paper with reference corresponding to the index of the bucket, we 
     increment the count for that bucket. The only exception is that for any paper with larger number of 
     reference than n, we put in the n-th bucket.

    Then we iterate from the back to the front of the buckets, whenever the total count exceeds the
     index of the bucket, meaning that we have the index number of papers that have reference greater 
     than or equal to the index. Which will be our h-index result. The reason to scan from the end of 
     the array is that we are looking for the greatest h-index. For example, given array [3,0,6,5,1], 
     we have 6 buckets to contain how many papers have the corresponding index. 
*/

#include<bits/stdc++.h>
using namespace std;
int hIndex(vector<int> &citations){
    int n = citations.size();
    vector<int> count(n+1, 0);
    for(int i=0; i<n; i++){
        if(citations[i] >= n)
            count[n]++;
        
        else
            count[citations[i]]++;
    }
    int total = 0;
    for(int i=n; i>=0; i--){
        total += count[i];
        if(total >= i)
            return i;
    }
    return 0;
}
int main(){
    vector<int> citations = {3,0,6,1,5};
    cout << hIndex(citations);
}