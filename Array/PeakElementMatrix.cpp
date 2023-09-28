/*
APPROACH =>
    1. We will apply BINARY SEARCH in every row.
    2. Why Binary Search❓
    - Because in the question it is specified we have to do it in O(mlogm).
    - And if we see carefully peak elem will be greater than prev and the 
    next elems.
    - So we can actually decide the half that if the curr elem is not peak elem
    check the max elem in left of mid and right of mid 
    if leftOfMidHalf > rightOfMidHalf then our peak elem is on the
    left half otherwise vice-versa.
    3. In every row for every mid we will find upper , down , left , right.
    4. Will find max of vertical = max(upper,down) and 
    max of horizontal = max(left,right).
    5. We will also find max Elem in leftHalf of Mid by max(left, mat[i][0]);
    leftHalf of Mid by max(right, mat[i][col-1]);
    6. for peak if mat[i][mid]>max(vertical,horizontal) we have found our peak.
    7. If leftHalf > rightHalf then our peak elem is on left Side (high=mid-1)
    otherwise our peak elem is on the right side (low=mid+1)
    8. O(nlogm)


*/


#include<bits/stdc++.h>
using namespace std;
vector<int> peakMatrix(vector<vector<int>> &mat){
    int rows = mat.size();
    int cols = mat[0].size();
    vector<int>ans;
    for(int i=0;i<rows;i++)
    {
        int low =0;
        int high = cols-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
                
            int upper = i > 0 ? mat[i][mid] : -1;
            int lower = i < rows-1 ? mat[i+1][mid] : -1;
            int left = mid > 0 ? mat[i][mid-1] : -1;
            int right = mid < cols-1 ? mat[i][mid+1] : -1;

            int maxVertical = max(upper,lower);
            int maxHorizontal = max(left,right);

            int maxLeftHalf = max(left,mat[i][0]);
            int maxRightHalf = max(right,mat[i][cols-1]);


            if(mat[i][mid] >= max(maxVertical, maxHorizontal))
            {
                ans.push_back(i);
                ans.push_back(mid);
                return ans;
            }
            else if(maxLeftHalf > maxRightHalf)
                high = mid-1;
            else
                low=mid+1;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> mat = {{10,20,15},{21,30,14},{7,16,32}};
    auto ans = peakMatrix(mat);
    cout << ans[0] << " " << ans[1];
}