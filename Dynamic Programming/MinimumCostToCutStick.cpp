#include<bits/stdc++.h>
using namespace std;
int func(int i, int j, vector<int> &cuts){
    if(i > j) 
        return 0;
    
    int minimum = INT_MAX;
    for(int index = i; index <= j; index++){
        int cost = cuts[j+1] - cuts[i-1] + func(i, index-1, cuts) + func(index+1, j, cuts);
        minimum = min(minimum, cost);
    }
    return minimum;
}
int minimumCostCut(int n, int c, vector<int> &cuts){
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    return func(1, c, cuts);
}
int main(){
    vector<int> cuts = {3,5,1,4};
	int c = cuts.size();
	int n = 7;
	cout << minimumCostCut(n, c, cuts);
	return 0;
}