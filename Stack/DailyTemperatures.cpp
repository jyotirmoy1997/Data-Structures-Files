#include<bits/stdc++.h>
using namespace std;
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n);
    stack<int> st;
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && temperatures[st.top()] <= temperatures[i])
            st.pop();

        if(st.empty())
            res[i] = 0;

        else
            res[i] = st.top() - i;
        
        st.push(i);
    }
    return res;
}
int main(){
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    auto res = dailyTemperatures(temperatures);
    for(auto it : res)
        cout << it << " ";
}