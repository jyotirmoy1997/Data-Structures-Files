#include<bits/stdc++.h>
using namespace std;
vector<int> unionOfArrays(int arr1[], int arr2[], int n1, int n2){
    vector<int> arr3;
    int i=0, j=0;
    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
            if(arr3.size() == 0 || arr3.back() != arr1[i]){
                arr3.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(arr3.size() == 0 || arr3.back() != arr2[j]){
                arr3.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i < n1){
        if(arr3.back() != arr1[i]){
            arr3.push_back(arr1[i]);
        }
        i++;
    }
    while(j < n2){
        if(arr3.back() != arr2[j]){
            arr3.push_back(arr2[j]);
        }
        j++;
    }
    return arr3;
}
int main()
{
    int arr1[] = {1, 1, 2, 3, 4, 5};
    int arr2[] = {2, 3, 4, 4, 5, 6};
    auto res = unionOfArrays(arr1, arr2, sizeof(arr1)/sizeof(int), sizeof(arr2)/sizeof(int));
    for(auto it : res){
        cout << it << " ";
    }
}