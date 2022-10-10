#include<bits/stdc++.h>
using namespace std;
vector<int> prevSmallerElement(int arr[], int n)
{
    vector<int> res(n);
    stack<int> st;
    st.push(-1);
    for(int i=0; i<n; i++)
    {
        int curr = arr[i];
        while(st.top() >= curr){
            st.pop();
        }
        res[i] = st.top();
        st.push(curr);
    }
    return res;
}
int main()
{
    int arr[] = {4, 8, 5, 2, 25};
    vector<int> res = prevSmallerElement(arr, sizeof(arr)/sizeof(int));
    for(auto it : res){
        cout << it << " ";
    }
}