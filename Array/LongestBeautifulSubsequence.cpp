/* Intuition
The main idea is to sort the array in ascending order and then iteratively(from largest to smallest elements)
construct a subsequence and check if the size of the subsequence is greater than ith element which means if we 
include this element in subsequence then overall result will be reduced hence break the loop here and return 
the length of subsequence.

Implementation
1. Sort the input array arr in ascending order.

2. Initialize two variables: ind to keep track of the length of subsequence while traversing the sorted array, 
and ans to store the length of the longest subsequence.

3. Start iterating through the sorted array from the end (largest elements).

4. Check if the current element at index i is greater than or equal to the value of ind. If it is, it means
 that this element can be part of the subsequence. Increment ans to indicate the inclusion of this element 
 in the subsequence.

5. If the current element is not greater than or equal to ind, break out of the loop as there is no need to 
continue checking further. We've already found the longest subsequence based on the problem's criteria.

6. Return the value of ans as the length of the longest subsequence.*/

#include <bits/stdc++.h>
using namespace std;
int longestSubsequenceLength(int n,vector<int> &arr){
    sort(begin(arr),end(arr));
    int ind=1,ans=0;
    for(int i=n-1;i>=0;i--){
        if(arr[i]>=ind)
            ans++;

        else
            break;

        ind++;
    }
    return ans;
}
int main(){
    vector<int> arr = {1, 2, 4, 5, 2};
    cout << longestSubsequenceLength(arr.size(), arr);
}