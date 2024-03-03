#include <bits/stdc++.h>
using namespace std;
string maximumOddBinaryNumber(string s) {
    int len = s.length(), totOnes = 0;
    for(auto it : s){
        if(it == '1')
            totOnes++;
    }
    string ans = "";
    totOnes--;
    int zerosRequired = (len - 1) - totOnes;
    for(int i=0; i<totOnes; i++)
        ans = '1' + ans;

    for(int i=0; i<zerosRequired; i++)
        ans += '0';
    
    ans += '1';
    return ans;
}
int main(){
    string s = "0101";
    cout << maximumOddBinaryNumber(s);
}