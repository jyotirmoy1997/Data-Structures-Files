#include<bits/stdc++.h>
using namespace std;
int chalkReplacer(vector<int>& chalk, int k){
    int sum = accumulate(chalk.begin(), chalk.end(), 0);
    int excessSumAfterMod = k % sum, n = chalk.size();
    for(int i=0; i<n; i++){
        if(excessSumAfterMod < chalk[i])
            return i;
        
        excessSumAfterMod -= chalk[i];
    }
    
    return 0;
}
int main(){
    vector<int> chalk = {3,4,1,2};
    int k = 25;
    cout << chalkReplacer(chalk, k);
}