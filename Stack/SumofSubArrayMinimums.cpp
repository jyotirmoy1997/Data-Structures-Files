#include<bits/stdc++.h>
using namespace std;
int sumSubarrayMins(vector<int>& arr){
    int n = arr.size();
    vector<int> ps(n), ns(n);
    stack<int> st;
    stack<int> st2;
    int MOD = 1e9 + 7;
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        
        if(st.empty())
            ps[i] = i + 1;
        else
            ps[i] = i - st.top();

        st.push(i);
    }
    for(int i=n-1; i>=0; i--){
        while(!st2.empty() && arr[st2.top()] > arr[i])
            st2.pop();
        
        if(st2.empty())
            ns[i] = n - i;
        else
            ns[i] = st2.top() - i;

        st2.push(i);
    }

    int res = 0;
    for(int i=0; i<n; i++){
        long long prod = (ps[i] * ns[i]) % MOD;
        prod = (prod * arr[i]) % MOD;
        res = (res + prod) % MOD;
    }
    return res;
}
int main()
{
    vector<int> nums = {2, 9, 7, 8, 3, 4, 6, 1};
    cout << sumSubarrayMins(nums);
}