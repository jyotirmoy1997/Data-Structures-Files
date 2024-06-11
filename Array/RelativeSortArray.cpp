#include<bits/stdc++.h>
using namespace std;
vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> freq;
    unordered_set<int> st;
    for(auto it : arr1)
        freq[it]++;

    vector<int> res;
    vector<int> rem;
    for(auto it : arr2){
        int numEl = freq[it];
        for(int i=0; i<numEl; i++)
            res.push_back(it);
        
        st.insert(it);
    }
    for(auto it : freq){
        if(st.find(it.first) == st.end()){
            int numEl = it.second;
            for(int i=0; i<numEl; i++)
                rem.push_back(it.first);
        }
    }
    sort(rem.begin(), rem.end());
    res.insert(res.end(), rem.begin(), rem.end());
    return res;
}
int main(){
   vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
   vector<int> arr2 = {2,1,4,3,9,6};
   auto res = relativeSortArray(arr1, arr2);
   for(auto it : res)
        cout << it << " ";
}