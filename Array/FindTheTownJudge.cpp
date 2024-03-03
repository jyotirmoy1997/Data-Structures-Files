#include<bits/stdc++.h>
using namespace std;
int findJudge(int n, vector<vector<int>>& trust){
    vector<int> indegree(n+1, 0), outdegree(n+1, 0);
    for(auto it : trust){
        outdegree[it[0]]++;
        indegree[it[1]]++; 
    }

    for(int i=1; i<=n; i++){
        if(outdegree[i] == 0 && indegree[i] == n-1)
            return i;
    }

    return -1;
}
int main(){
    int n = 3;
    vector<vector<int>> trust = {{1,3},{2,3},{3,1}};
    cout << findJudge(n, trust);
}