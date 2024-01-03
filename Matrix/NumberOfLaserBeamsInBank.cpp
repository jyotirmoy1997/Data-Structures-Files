#include<bits/stdc++.h>
using namespace std;
int numberOfBeams(vector<string>& bank) {
    int n = bank.size(), m = bank[0].size(), total = 0, lastRowCount = 0;
    for(int i=0; i<n; i++){
        int count = 0;
        for(int j=0; j<m; j++){
            if(bank[i][j] == '1')
                count++;
        }
        if(count > 0){
            total += lastRowCount * count;
            lastRowCount = count;
        }
    }
    return total;
}
int main(){
    vector<string> bank = {"011001","000000","010100","001000"};
    cout << numberOfBeams(bank);
}