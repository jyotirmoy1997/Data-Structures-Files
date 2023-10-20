#include<bits/stdc++.h>
using namespace std;

// Custom comparator to sort the array in decreasing order according to value/weight
bool comp(pair<int, int> a, pair<int, int> b){
    double r1 = (double)a.second/(double)a.first;
    double r2 = (double)b.second/(double)b.first;

    return r1 > r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(), items.end(), comp);
    int currWeight = 0;
    double finalVal = 0.0;
    for(int i=0; i<n; i++){
        if(currWeight + items[i].first <= w){
            currWeight += items[i].first;
            finalVal += items[i].second;
        }
        else{
            int rem = w - currWeight;
            finalVal += (items[i].second / (double)items[i].first) * (double)rem;
            break;
        }
    }
    return finalVal;
}
int main(){
    // {weight, value}
    vector<pair<int, int>> items = {{10, 60}, {20, 100}, {30, 120}};
    int weight = 50;
    cout << maximumValue(items, items.size(), weight);
}