#include<bits/stdc++.h>
using namespace std;
int maxScore(string s){
    int n = s.size();
    int c0 = 0, c1 = 0;
    int maxi = -1;
    unordered_map<int, pair<int, int>> mpp;
    for(int i=0; i<n; i++){
        if(s[i] == '0')
            c0++;
        
        else if(s[i] == '1')
            c1++;
        
        mpp[i] = make_pair(c0, c1);
    }
    
    for(int i=0; i<n-1; i++){
        int currValue = mpp[i].first + c1 - mpp[i].second;
        maxi = max(maxi, currValue);
    }

    return maxi;
}
int main(){
    string s = "011101";
    cout << maxScore(s);
}