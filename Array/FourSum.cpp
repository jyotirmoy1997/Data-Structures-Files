/* Approach =>  Sort the array and then apply two pointer


*/

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSumOptimal(vector<int> &arr, int n, int target){
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        if(i != 0 && arr[i] == arr[i-1])
            continue;
        for(int j=i+1; j<n; j++){
            if(j != i+1 && arr[j] == arr[j-1])
                continue;

            int k = j + 1;
            int l = n - 1;
            while(k < l){
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if(sum < target)
                    k++;
                        
                else if(sum > target)
                    l--;
                        
                else{
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k < l && arr[k] == arr[k-1])
                        k++;
                            
                    while(k < l && arr[l] == arr[l+1])
                        l--;
                }
            }
        }
        
    }
    return ans;
}
int main()
{
    vector<int> arr = {1,0,-1,0,-2,2};
    auto ans = fourSumOptimal(arr, arr.size(), 0);
    for(auto it : ans){
        for(auto el : it)
            cout << el << " ";
        
        cout << endl;
    }
        
}