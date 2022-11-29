/* Given two sorted arrays, the task is to calculate the median of two sorted arrays.

Naive Approach :: Use the Merge Function of merge sort and count the half position =>

TC => O(n) 

Efficient Solution => https://www.youtube.com/watch?v=NTop3VTjmxk

TC => O(logN)*/

#include<bits/stdc++.h>
using namespace std;
double medianSortedArrays(int arr1[], int arr2[], int n1, int n2)
{
    if(n1 > n2){
        swap(arr1, arr2);
    }
    int low = 0, high = n1;
    while(low <= high){
        int cut1 = (low + high)/2;
        int cut2 = (n1 + n2 + 1)/2 - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1-1];
        int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2-1];

        int right1 = (cut1 == n1) ? INT_MAX : arr1[cut1];
        int right2 = (cut2 == n2) ? INT_MAX : arr2[cut2];

        if(left1 <= right2 && left2 <= right1){
            if((n1 + n2) % 2 == 0){
                return (max(left1, left2) + min(right1, right2))/2;
            }
            else{
                return max(left1, left2);
            }
        }
        else if(left1 > right2){
            high = cut1 - 1;  
        }
        else{
            low = cut1 + 1;
        }
    }
    return 0;
}
int main()
{
    int arr1[] = {2, 6, 8, 12, 90, 120};
    int arr2[] = {5, 8, 14, 35, 55, 60, 150, 200};
    cout << medianSortedArrays(arr1, arr2, sizeof(arr1)/sizeof(int), sizeof(arr2)/sizeof(int));
}