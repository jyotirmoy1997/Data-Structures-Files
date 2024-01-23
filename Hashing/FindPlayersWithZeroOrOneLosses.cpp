#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> findWinners(vector<vector<int>>& matches){
    map<int, int> winnersMap;
    map<int, int> losersMap;
    for(auto it : matches){
        winnersMap[it[0]]++;
        losersMap[it[1]]++;
    }
    vector<vector<int>> res;

    vector<int> winners;
    for(auto it : winnersMap){
        if(losersMap.find(it.first) == losersMap.end())
            winners.push_back(it.first);
    }

    vector<int> losers;
    for(auto it : losersMap){
        if(it.second == 1)
            losers.push_back(it.first);
    }

    res.push_back(winners);
    res.push_back(losers);
    return res;
}
int main(){
    vector<vector<int>> matches = {{1,3},{2,3},{3,6},{5,6},{5,7},{4,5},{4,8},{4,9},{10,4},{10,9}};
    auto res = findWinners(matches);

    for(auto it : res){
        for(auto el : it)
            cout << el << " ";

        cout << endl;
    }
}