#include<bits/stdc++.h>
using namespace std;
long long sumSubarrayMins(vector<int>& arr){
    int n = arr.size();
    vector<int> ps(n), ns(n), pg(n), ng(n);
    stack<int> st;

    //  Previous Smaller Element
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        
        if(st.empty())
            ps[i] = i + 1;
        else
            ps[i] = i - st.top();

        st.push(i);
    }

    while(!st.empty())
        st.pop();

    // Next Smaller Element
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        
        if(st.empty())
            ns[i] = n - i;
        else
            ns[i] = st.top() - i;

        st.push(i);
    }

    while(!st.empty())
        st.pop();

    // Previous Greater Element
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] <= arr[i])
            st.pop();
        
        if(st.empty())
            pg[i] = i + 1;
        else
            pg[i] = i - st.top();

        st.push(i);
    }

    while(!st.empty())
        st.pop();

    // Next Greater Element
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] < arr[i])
            st.pop();
        
        if(st.empty())
            ng[i] = n - i;
        else
            ng[i] = st.top() - i;

        st.push(i);
    }

    long long res = 0;
    for(int i=0; i<n; i++){
        res += (ng[i] * pg[i] - ns[i] * ps[i]) * arr[i];
    }
    return res;
}
int main()
{
    vector<int> nums = {4,-2,-3,4,1};
    cout << sumSubarrayMins(nums);
}