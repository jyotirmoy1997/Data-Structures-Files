#include<bits/stdc++.h>
using namespace std;
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int count = 0, i = 0, j = 0, n1 = g.size(), n2 = s.size();
    while(i < n1 && j < n2){
        if(g[i] <= s[j]){
            i++;
            j++;
            count++;
        }
        else
        j++;
    }
    return count;
}
int main(){
    vector<int> g = {10,9,8,7};
    vector<int> s = {5,6,7,8};
    cout << findContentChildren(g, s);
}