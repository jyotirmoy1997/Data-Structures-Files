#include <bits/stdc++.h>
using namespace std;
pair<int, int> repeatMissing(vector<int> &arr){
    int n = arr.size();
    int s1n = (n * (n+1))/2;
    int s2n = (n * (n+1) * (2 * n + 1))/6;
    int s1 = 0, s2 = 0;
    for(int i=0; i<n; i++){
        s1 += arr[i];
        s2 += arr[i] * arr[i];
    }
    int val1 = s1 - s1n;
    int val2 = s2 - s2n;
    val2 /= val1;
    int x = (val1 + val2)/2;
    int y = x - val1;
    return make_pair(x, y);
}
int main()
{
	vector<int> arr = {4, 3, 6, 2, 1, 1};
    auto it = repeatMissing(arr);
    cout << it.first << " " << it.second;
}
