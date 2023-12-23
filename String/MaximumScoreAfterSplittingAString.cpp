#include<bits/stdc++.h>
using namespace std;
int countZeros(string &s, int start, int end){
    int count = 0;
    while(start < end){
        if(s[start] == '0')
            count++;
        
        start++;
    }
    return count;
}
int countOnes(string &s, int start, int end){
    int count = 0;
    while(start < end){
        if(s[start] == '1')
            count++;
        
        start++;
    }
    return count;
}
int maxScore(string s){
    int maxi = -1e9, n = s.length();
    for(int i=0; i<n-1; i++){
        int zeros = countZeros(s, 0, i+1);
        int ones = countOnes(s, i+1, n);
        maxi = max(maxi, zeros + ones);
    }
    return maxi;
}
int main(){

}