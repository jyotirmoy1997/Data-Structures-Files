#include<bits/stdc++.h>
using namespace std;
int countbits(int n){
    int count = 0;
    while(n != 0){
        if(n & 1 == 1)
            break;
            
        count++;
        n = n >> 1;
    }
    return count;
}
void numbers(vector<int> &arr){
    int XOR = 0, XOR1 = 0, XOR2 = 0;
    for(auto it : arr){
        XOR ^= it;
    }
    int setBit = countbits(XOR);
    for(auto it : arr){
        if(it & (1 << setBit))
            XOR1 ^= it;
        
        else
            XOR2 ^= it;
    }

    cout << "Two Numbers are :: " << XOR1 << "-" << XOR2;
}
int main(){
    vector<int> arr = {2, 1, 2, 5, 1, 4, 4, 7, 3, 3};
    numbers(arr);
}