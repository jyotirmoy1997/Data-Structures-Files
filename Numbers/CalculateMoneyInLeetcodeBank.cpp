#include<bits/stdc++.h>
using namespace std;
int totalMoney(int n) {
    int monday = 0, sum = 0, i = 0, curr = monday;
    for(int i=0; i<n; i++){
        if(i % 7 == 0){
            monday++;
            curr = monday;
        }
        else
            curr++;
        sum += curr;
    }
    return sum;
}
int main(){

}