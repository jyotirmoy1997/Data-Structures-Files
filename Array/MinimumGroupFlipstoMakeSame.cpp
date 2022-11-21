/* Given a binary array, the task is to find the minimum group that can be flipped
to make all the array elements same */

#include<bits/stdc++.h>
using namespace std;
void printGroups(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        if(arr[i] != arr[i-1])
        {
            if(arr[i] != arr[0]){
                cout << "From " << i << "to";
            }
            else
                cout << i-1 << endl;
        }
    }
    if(arr[n-1] != arr[0]){
        cout << n-1 << endl;
    }
    
}
int main()
{
    int arr[] = {0, 0, 1, 1, 0, 0, 1, 1, 0, 1};
    printGroups(arr, sizeof(arr)/sizeof(int));
}