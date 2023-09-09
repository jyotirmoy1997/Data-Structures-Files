#include<bits/stdc++.h>
using namespace std;
class MyQueue {
    stack<int> st1;
    stack<int> st2;
    public:
        MyQueue() {}
        
        void push(int x) {
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            st2.push(x);
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
        }
        
        int pop() {
            int val = st1.top();
            st1.pop();
            return val;
        }
        
        int peek() {
            return st1.top();
        }
        
        bool empty() {
            return st1.empty();
        }
};

int main(){
    MyQueue q;
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    cout << q.peek() << " ";
    q.pop();
    cout << q.peek() << " ";
}