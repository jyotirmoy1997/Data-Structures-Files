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
        if(ps[i] < 0)
            maxi = max(maxi, ns[i] * arr[i]);
        
        else
            maxi = max(maxi, (ns[i] - ps[i] - 1) * arr[i]);
    }

    return maxi;
}

int maxRectangleMatrix(vector<vector<char>> &mat){
    int n = mat.size(), m = mat[0].size();
    vector<int> arr(m, 0);
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << mat[i][j] << " ";
            arr[j] = (mat[i][j] == '1') ? arr[j] + 1 : 0;
        }
        maxi = max(maxi, largestRectangleArea(arr));
    }
    return maxi;
}
int main()
{
    // vector<vector<char>> mat = {{'1','0','1','0','0'},
    //                             {'1','0','1','1','1'},
    //                             {'1','1','1','1','1'},
    //                             {'1','0','0','1','0'}};

    vector<vector<char>> mat = {{'1', '0'}};
    cout << maxRectangleMatrix(mat);
}