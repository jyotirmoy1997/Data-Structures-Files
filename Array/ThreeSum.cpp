/* Approach =>  Sort the array and then apply two pointer


*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSumBetter(vector<int> &arr, int n){
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        unordered_set<int> hs;
        for(int j=i+1; j<n; j++){
            int third = -(arr[i] + arr[j]);
            if(hs.find(third) != hs.end()){
                vector<int> v = {arr[i], arr[j], third};
                sort(v.begin(), v.end());
                st.insert(v);
            }
            hs.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}



vector<vector<int>> threeSumOptimal(vector<int> &arr, int n){
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        if(i != 0 && arr[i] == arr[i-1])
            continue;
        
        int j = i + 1;
        int k = n - 1;
        while(j < k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0)
                j++;
            
            else if(sum > 0)
                k--;
            
            else{
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j < k && arr[j] == arr[j-1])
                    j++;
                
                while(j < k && arr[k] == arr[k+1])
                    k--;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {-1,0,1,2,-1,-4};
    auto ans = threeSumOptimal(arr, arr.size());
    for(auto it : ans){
        for(auto el : it)
            cout << el << " ";
        
        cout << endl;
    }
        
}