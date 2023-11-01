#include<bits/stdc++.h>
using namespace std;
void rec(int index, int sum, vector<int> &num, vector<int> &res){
    if(index == num.size()){
        res.push_back(sum);
        return;
    }

    // Take
    sum += num[index];
    rec(index + 1, sum, num, res);
    
    // Not Take
    sum -= num[index];
    rec(index + 1, sum, num, res);
}
vector<int> subsetSum(vector<int> &num){
	vector<int> res;
    rec(0, 0, num, res);
    sort(res.begin(), res.end());
    return res;	
}
int main(){
    vector<int> num = {3, 1, 2};
    auto res = subsetSum(num);
    for(auto it : res)
        cout << it << " ";
}