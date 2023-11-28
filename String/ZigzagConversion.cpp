#include<bits/stdc++.h>
using namespace std;
string convert(string s, int numRows){
    if(numRows == 1)
        return s;

    string ans = "";
    int len = s.length();
    for(int row=0; row <numRows; row++){
        int increment = 2 * (numRows - 1);
        for(int i=row; i<len; i += increment){
            ans += s[i];
            int middleCharIndex = i + increment - 2 * row;
            if((row > 0 && row < numRows - 1) && (middleCharIndex < len))
                ans += s[middleCharIndex];
        }
    }
    return ans;
}
int main(){
    string s = "PAYPALISHIRING";
    int numRows = 4;
    cout << convert(s, numRows);
}