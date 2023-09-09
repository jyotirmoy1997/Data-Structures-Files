#include<bits/stdc++.h>
using namespace std;

// This Approach uses 2 queues
class Stack
{
    queue<int> q1;
    queue<int> q2;
    public:
        Stack() {
            
        }
        
        void push(int x) {
            q1.push(x);
        }
        
        int pop() {
            while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            int popVal = q1.front();
            q1.pop();
            swap(q1, q2);
            return popVal;
        }
        
        int top() {
             while(q1.size() > 1){
                q2.push(q1.front());
                q1.pop();
            }
            int topVal = q1.front();
            q2.push(q1.front());
            q1.pop();
            swap(q1, q2);
            return topVal;
        }
        
        bool empty() {
            return q1.empty();
        }
};

// This Approach uses 1 queue
class Stack2
{
    queue<int> q1;
    public:
        Stack2() {}
        
        void push(int x) {
            q1.push(x);
            for(int i=0; i < q1.size() - 1; i++){
                q1.push(q1.front());
                q1.pop();
            }
        }
        
        int pop() {
            int popVal = q1.front();
            q1.pop();
            return popVal;
        }
        
        int top() {
            return q1.front();
        }
        
        bool empty() {
            return q1.empty();
        }
};
int main(){
    Stack st;
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(11);
    st.push(2);
    cout << st.pop() << " ";
    cout << st.top() << " ";
}