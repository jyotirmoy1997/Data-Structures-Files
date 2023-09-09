#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach => keep the min element along side the curreny element
// class MinStack {
//     stack<pair<int, int>> st;
//     int mini;
//     public:
//         MinStack() {
//             mini = INT_MAX;
//         }
        
//         void push(int val) {
//             mini = min(mini, val);
//             st.push(make_pair(val, mini));
//         }
        
//         void pop() {
//             st.pop();
//         }
        
//         int top() {
//             return st.top().first;
//         }
        
//         int getMin() {
//             return st.top().second;
//         }
// };


class MinStack {
    stack<pair<int, int>> st;
    int mini;
    public:
        MinStack() {
            mini = INT_MAX;
        }
        
        void push(int val) {
            mini = min(mini, val);
            st.push(make_pair(val, mini));
        }
        
        void pop() {
            st.pop();
        }
        
        int top() {
            return st.top().first;
        }
        
        int getMin() {
            return st.top().second;
        }
};


int main(){
   
}