#include<bits/stdc++.h>
using namespace std;
int removeElement(vector<int>& nums, int val){
    int index = 0, n = nums.size();
    for(int i=0; i<n; i++){
        if(nums[i] != val){
            swap(nums[index], nums[i]);
            index++;
        }
    }
    return index;
}
int main(){
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    cout << removeElement(nums, val);
}