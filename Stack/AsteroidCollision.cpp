#include<bits/stdc++.h>
using namespace std;
// vector<int> asteroidCollision(vector<int>& arr){
//     vector<int> res;
//     stack<int> st;
//     int n = arr.size();
//     st.push(arr[0]);
//     for(int i=1; i<n; i++){
//         if(arr[i] > 0)
//             st.push(arr[i]);

//         else if(arr[i] < 0){
//             while(!st.empty() && st.top() > 0 && abs(arr[i]) > abs(st.top()))
//                st.pop(); 

//             if(st.empty() || st.top() < 0)
//                 st.push(arr[i]);
            
//             else if(st.top() == abs(arr[i]))
//                 st.pop();
//         }
//     }
//     while(!st.empty()){
//         res.push_back(st.top());
//         st.pop();
//     }
//     reverse(res.begin(), res.end());
//     return res;
// }
vector<int> asteroidCollision(vector<int>& arr){
    vector<int> ans;
    int n = arr.size();
    ans.push_back(arr[0]);
    for(int i=1; i<n; i++){
        if(arr[i] > 0)
            ans.push_back(arr[i]);

        else if(arr[i] < 0){
            while(ans.size() > 0 && ans.back() > 0 && abs(arr[i]) > abs(ans.back()))
               ans.pop_back(); 

            if(ans.size() == 0 || ans.back() < 0)
                ans.push_back(arr[i]);
            
            else if(ans.back() == abs(arr[i]))
                ans.pop_back();
        }
    }
    return ans;
}
int main(){
    vector<int> asteroids = {10,2,-5};
    asteroidCollision(asteroids);
}