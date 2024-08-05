#include<bits/stdc++.h>
using namespace std;
string kthDistinct(vector<string>& arr, int k){
    unordered_map<string, int> freq;
    for(auto it : arr)
        freq[it]++;
    
    int count = 0;
    for(auto it : arr){
        if(freq[it] == 1){
            count++;
            if(count == k)
                return it;
        }
    }
    return "";
}
int main(){

}