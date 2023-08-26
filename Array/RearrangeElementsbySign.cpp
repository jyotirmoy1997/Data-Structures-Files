#include <bits/stdc++.h>
using namespace std;
void rearrangeElementsBrute(int arr[], int n)
{
	vector<int> vec1;
    vector<int> vec2;
    for(int i=0; i<n; i++){
        if(arr[i] < 0)
            vec2.push_back(arr[i]);
        else  
            vec1.push_back(arr[i]);
    }
    int k = 0, c1 = 0, c2 = 0;
    while(k < n){
        if(k % 2 == 0){
            arr[k] = vec1[c1];
            c1++;
        }
        else{
            arr[k] = vec2[c2];
            c2++;
        }
         k++;   
    }
}
vector<int> rearrangeElementsOptimal(int arr[], int n)
{
	vector<int> ans(n);
    int pos = 0;
    int neg = 1;
    for(int i=0; i<n; i++){
        // cout << pos << " " << neg << endl;
        if(arr[i] >= 0){
            ans[pos] = arr[i];
            pos += 2;
        }
            
        else if(arr[i] < 0){
            ans[neg] = arr[i];
            neg += 2;
        }   
    }
    return ans;
}
int main() {
	int arr[] = {3,1,-2,-5,2,-4};
	auto ans = rearrangeElementsOptimal(arr, sizeof(arr)/sizeof(int));
    for(auto it : ans){
        cout << it << " ";
    }
	return 0;
}
