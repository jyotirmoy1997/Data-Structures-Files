#include<bits/stdc++.h>
using namespace std;
bool knows(vector<vector<int>> &mat, int a, int b){
    return mat[a][b] == 1;
}
int celebrity(vector<vector<int>> &mat){
    int n = mat.size();
    stack<int> st;
    for(int i=0; i<n; i++)
        st.push(i);

    while(st.size() > 1){
        int a = st.top();
        st.pop();

        int b = st.top();
        st.pop();

        if(knows(mat, a, b))
            st.push(b);
        
        else  
            st.push(a);
    }
    int candidate = st.top();
    st.pop();
    bool flag1 = false;
    bool flag2 = false;
    for(int i=0; i<n; i++){
        if(candidate != i && mat[candidate][i] == 0)
            flag1 = true;
        else 
            flag1 = false;
    }
    for(int i=0; i<n; i++){
        if(candidate != i && mat[i][candidate] == 1)
            flag2 = true;
        else if(candidate != i && mat[i][candidate] == 0) 
            flag2 = false;
    }
    if(flag1 && flag2)
        return candidate;
    
    return -1;
}
int main()
{
    vector<vector<int>> mat = { {0, 1, 0},
                                {0, 0, 0},
                                {0, 1, 0}};

    cout << celebrity(mat);
    // vector<vector<char>> mat = {{'1', '0'}};
    // cout << maxRectangleMatrix(mat);
}