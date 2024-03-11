#include<bits/stdc++.h>
using namespace std;
vector<int> intersectionOfArrays(int arr1[], int arr2[], int n1, int n2){
    vector<int> arr3;
    int i=0, j=0;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr1[i] > arr2[j]){
            j++;
        }
        else{
            arr3.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return arr3;
}
int main()
{
    int arr1[] = {1, 2, 2, 3, 3, 4, 5, 6};
    int arr2[] = {2, 3, 3, 5, 6, 6, 7};
    auto res = intersectionOfArrays(arr1, arr2, sizeof(arr1)/sizeof(int), sizeof(arr2)/sizeof(int));
    for(auto it : res){
        cout << it << " ";
    }
}