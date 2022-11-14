/* Given an array, the task is to find the maximum sum of all circular sub arrays*/

/* In Naive Approach, the idea is to calculate the sub array sum for each 
sub array(including the circular ones) and then find the maximum of the all 
sub arrays */

#include<bits/stdc++.h>
using namespace std;
int maxCircularSubArrayNaive(int arr[], int n)
{
   int res = arr[0], max_ending = arr[0];
   for(int i=0; i<n; i++)
   {
    int curr_max = arr[i], curr_sum = arr[i];
    for(int j=1; j<n; j++){
        int index = (i + j) % n;
        curr_sum += arr[index];
        curr_max = max(curr_sum, curr_max); 
    }
    res = max(res, curr_max);
   }
   return res;
}


/*In the efficient approach, we are computing the maximum sum for the normal sub array as well
as the circular sub arrays. The Idea is to the find the minimum sum sub array using inverted array
elements and Kadane's Algorithm, then to subtract it from the main sum of array. */
int maxSumSubArray(int arr[], int n){
    int res = arr[0], max_ending = arr[0];
    for(int i=1; i<n; i++){
        max_ending = max(max_ending + arr[i], arr[i]);
        res = max(max_ending, res);
    }
    return res;
}

int maxCircularSubArrayEfficient(int arr[], int n)
{
    /* The First task is to compute the maximum sum of normal sub arrays*/
    int max_normal = maxSumSubArray(arr, n);
    if (max_normal < 0){
        return max_normal;
    }

    /* The Second task is to compute the sum and invert the array elements*/
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        arr[i] = -arr[i];
    }

    /* After inverting the array, we are computing the minimum sum sub array 
    with the same function, as the elements are inverted, this is going to return 
    the minimum sum. Now, we add it to the sum(basically subtracting the minimum sum)*/
    int max_circular = sum + maxSumSubArray(arr, n);

    /*The last step is to return the maximum between the normal sub array sum
    and the maximum sub array sum */

    return max(max_normal, max_circular);
}

int main()
{
    int arr[] = {5, -2, 3, 4};
    cout << maxCircularSubArrayEfficient(arr, sizeof(arr)/sizeof(int));
}