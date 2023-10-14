/* Approch => As it is already told it is a valid parantheses, simply count the maximum 
number of opening brackets : (*/

#include<bits/stdc++.h>
using namespace std;
int maxDepth(string s){
    int count = 0, maxi = 0, l = s.length();
    for(int i=0; i<l; i++){
        if(s[i] == '('){
            count++;
            maxi = max(maxi, count);
        }
        else if(s[i] == ')')
            count--;
    }
    return maxi;
}
int main(){
    string s = "(1+(2*3)+((8)/4))+1";
    cout << maxDepth(s);
}