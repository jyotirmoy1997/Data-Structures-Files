#include<bits/stdc++.h>
using namespace std;
int getCommon(vector<int>& nums1, vector<int>& nums2) {
    int min1 = 0, min2 = 0, n1 = nums1.size(), n2 = nums2.size();
    while(min1 < n1 && min2 < n2){
        if(nums1[min1] == nums2[min2])
            return nums1[min1];

        else if(nums1[min1] < nums2[min2])
            min1++;
        
        else
            min2++;
    }
    return -1;
}
int main(){

}