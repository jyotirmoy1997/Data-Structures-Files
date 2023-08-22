#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(int arr[], int n){
    int s = 0, e = n-1;
    while(s < e){
        if(arr[s] != arr[e])
            return false;
        s++;
        e--;
    }
    return true;
}
int main(){
   int arr[] = {10, 12, 4, 6, 4, 12, 10};
   int n = sizeof(arr)/sizeof(int);
   cout << isPalindrome(arr, n);

}