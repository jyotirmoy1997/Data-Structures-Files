#include<bits/stdc++.h>
using namespace std;
int sumSubarrayMins(vector<int>& arr){
    int n = arr.size();
    vector<int> ps(n), ns(n);
    stack<int> st;
    stack<int> st2;
    int MOD = 1e9 + 7;

    // Here, we are storing the difference of the indices between the curr and prev smaller element
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        
        if(st.empty())
            ps[i] = i + 1;
        else
            ps[i] = i - st.top();

        st.push(i);
    }

    // Here, we are storing the difference of the indices between the curr and next smaller element
    for(int i=n-1; i>=0; i--){
        while(!st2.empty() && arr[st2.top()] > arr[i])
            st2.pop();
        
        if(st2.empty())
            ns[i] = n - i;
        else
            ns[i] = st2.top() - i;

        st2.push(i);
    }

    // for(auto it : ps)
    //     cout << it << " ";

    // cout << endl;

    // for(auto it : ns)
    //     cout << it << " ";

    // cout << endl;

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
    vector<int> nums = {3, 1, 2, 4};
    cout << sumSubarrayMins(nums);
}