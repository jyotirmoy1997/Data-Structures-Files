#include<bits/stdc++.h>
using namespace std;
int longestConsecutiveSequence(vector<int> &arr){
    int n = arr.size();
    if(n == 0)
        return 0;

    int longest = 1;
    unordered_set<int> st;
    for(int i=0; i<n; i++)
        st.insert(arr[i]);

    for(auto it : st){
        if(st.find(it - 1) == st.end()){
            int x = it;
            int count = 1;
            while(st.find(x+1) != st.end()){
                count++;
                x++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}   
int main(){
    vector<int> arr = {100,4,200,1,3,2};
    cout << longestConsecutiveSequence(arr);
}