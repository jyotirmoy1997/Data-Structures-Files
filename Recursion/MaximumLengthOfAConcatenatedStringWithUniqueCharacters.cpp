#include<bits/stdc++.h>
using namespace std;
int func(int index, string s, vector<string>& arr){
    if(index == arr.size())
        return s.length();

    // Not Take Case
    int notTake = func(index + 1, s, arr);

    // Take Case
    int take = -1e9;
    unordered_set<char> st;
    bool flag = false;
    for(int i=0; i<s.length(); i++){
        if(st.find(s[i]) != st.end())
            flag = true;
        
        else
            st.insert(s[i]);
    }
    string curr = arr[index];
    for(int i=0; i<curr.length(); i++){
        if(st.find(curr[i]) != st.end())
            flag = true;

        else if(s.length() == 0)
            st.insert(curr[i]);
    }
    if(!flag){
        take = func(index + 1, s + curr, arr);
    }
    return max(take, notTake);
}
int maxLength(vector<string>& arr) {
    return func(0, "", arr); 
}
int main(){

}