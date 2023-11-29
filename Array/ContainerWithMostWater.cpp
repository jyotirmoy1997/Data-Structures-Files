#include<bits/stdc++.h>
using namespace std;

/* Note => This is the brute force solution.
In this solution, we try out every possible combo of area with a left pointer 
and a right pointer */ 
int maxAreaBrute(vector<int>& height){
    int res = 0, n = height.size();
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int area = (j - i) * min(height[i], height[j]);
            res = max(res, area);
        }
    }
    return res;
}

// The optimal solution uses two pointer approach
int maxArea(vector<int>& height) {
    int res = 0, left = 0, right = height.size() - 1;
    while(left < right){
        int area = (right - left) * min(height[left], height[right]);
        res = max(area, res);
        if(height[left] < height[right])
            left++;
        
        else
            right--;
    }
    return res;
}
int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height);
}