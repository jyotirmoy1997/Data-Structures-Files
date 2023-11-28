#include<bits/stdc++.h>
using namespace std;
int stringMatch(string text, string pattern){
    int n = text.length(), m = pattern.length(), i = 0, j = 0;
    for(i=0; i<=n - m; i++){
        for(j=0; j<m; j++){
            if(text[i+j] != pattern[j])
                break;
        }
        if(j == m)
            return i;
    }
    return -1;
}
int main(){
    string text = "PAYPALCGLEPALGOM";
    string pattern = "PALG";
    cout << stringMatch(text, pattern);
}