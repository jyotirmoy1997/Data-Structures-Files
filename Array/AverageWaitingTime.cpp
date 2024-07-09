#include<bits/stdc++.h>
using namespace std;
double averageWaitingTime(vector<vector<int>>& customers){
    int start_time = customers[0][0], n = customers.size();
    int elapsed_time = start_time + customers[0][1];
    double waiting_time = elapsed_time - start_time;
    for(int i=1; i<n; i++){
        if(customers[i][0] < elapsed_time)
            elapsed_time += customers[i][1]; 
        
        else
            elapsed_time = customers[i][0] + customers[i][1];
        
        waiting_time += elapsed_time - customers[i][0]; 
    }
    return waiting_time/n;
}
int main(){

}