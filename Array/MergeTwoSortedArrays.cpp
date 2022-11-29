#include<bits/stdc++.h>
using namespace std;
vector<int> mergeSortedArrays(int arr1[], int arr2[], int n1, int n2){
    vector<int> arr3(n1+n2, 0);
    int i=0, j=0, k=0;
    while(i < n1 && j < n2){
        if(arr1[i] < arr2[j]){
            arr3[k] = arr1[i];
            i++;
        }
        else{
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        cout << "Reach";
        arr3[k] = arr1[i];
        i++;
        k++;
    }
    while(j < n2){
        arr3[k] = arr2[j];
        j++;
        k++;
    }
    return arr3;
}
int main()
{
    int arr1[] = {2, 6, 8, 12, 90, 120};
    int arr2[] = {5, 8, 14, 35, 55, 60, 150, 200};
    auto res = mergeSortedArrays(arr1, arr2, sizeof(arr1)/sizeof(int), sizeof(arr2)/sizeof(int));
    for(auto it : res){
        cout << it << " ";
    }
}