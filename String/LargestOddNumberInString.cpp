#include<bits/stdc++.h>
using namespace std;
string largestOddNumber(string num){
    string s = "";
    int l = num.length();
    while(l >= 0){
        int n = int(num[l]) - 48;
        if(n % 2 == 1)
            break;
        
        l--;
    }
    for(int i=0; i<=l; i++){
        s += num[i];
    }
    return s;
}
int main(){
    string num = "420610";
    cout << largestOddNumber(num);
}