#include <bits/stdc++.h>
using namespace std;

// Better Solution => Pre-compute the left max and right max
int trapRainWaterBetter(vector<int>& height){
    int res = 0, n = height.size();
    vector<int> lmax(n, -1);
    vector<int> rmax(n, -1);
    lmax[0] = height[0];
    rmax[n-1] = height[n-1];

    for(int i=1; i<=n-1; i++)
        lmax[i] = max(lmax[i-1], height[i]);
    
    for(int i=n-2; i>=0; i--)
        rmax[i] = max(rmax[i+1], height[i]);

    for(int i=1; i<n-1; i++)
        res += min(lmax[i], rmax[i]) - height[i];

    return res;
}

// Optimal Solution => Uses Two Pointer Approach
int trapRainWaterOptimal(vector<int>& height){
    int res = 0, n = height.size();
    int left = 0, right = n-1;
    int lmax = 0, rmax = 0;
    while(left <= right){
        if(height[left] <= height[right]){
            if(height[left] >= lmax)
                lmax = height[left];
            
            else
                res += lmax - height[left];
            
            left++;
        }
        else{
            if(height[right] >= rmax)
                rmax = height[right];
            
            else
                res += rmax - height[right];

            right--;
        }
    }
    return res;
}
int main() {
	vector<int> height = {5, 0, 6, 2, 3};
	cout << trapRainWaterOptimal(height);
	return 0;
}
