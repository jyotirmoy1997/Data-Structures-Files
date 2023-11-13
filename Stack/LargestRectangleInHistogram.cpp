#include<bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>& arr) {
    int n = arr.size();
    vector<int> ps(n), ns(n);
    stack<int> st;

    //  Previous Smaller Element
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        
        if(st.empty())
            ps[i] = -1;
        else
            ps[i] = st.top();

        st.push(i);
    }

    while(!st.empty())
        st.pop();

    // Next Smaller Element
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] > arr[i])
            st.pop();
        
        if(st.empty())
            ns[i] = n;
        else
            ns[i] = st.top();

        st.push(i);
    }

    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        // ps[i] < 0 means it is the starting point of a new rectangle and the current element is the 
        // largest upto index i
        if(ps[i] < 0)
            maxi = max(maxi, ns[i] * arr[i]);
        
        // Otherwise, there is an element which is smaller than the current element.
        else
            maxi = max(maxi, (ns[i] - ps[i] - 1) * arr[i]);
    }

    return maxi;
}
int main()
{
    vector<int> nums = {2,1,5,6,2,3};
    cout << largestRectangleArea(nums);
}