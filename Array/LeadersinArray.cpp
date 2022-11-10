#include <bits/stdc++.h>
using namespace std;
void leaders(int arr[], int n)
{
	int curr_leader = arr[n-1];
    stack<int> st;
    st.push(arr[n-1]);
    for(int i=n-2; i>=0; i--)
    {
        if(arr[i] > curr_leader){
            st.push(arr[i]);
            curr_leader = arr[i];
        }
    }
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}
int main() {
	int arr[] = {7, 10, 4, 3, 6, 5, 2};
	leaders(arr, sizeof(arr)/sizeof(int));
	return 0;
}
