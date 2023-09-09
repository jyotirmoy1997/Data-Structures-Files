#include<bits/stdc++.h>
using namespace std;
class Stack
{
    int max_size;
    int *arr;
    int top;
    public:
        Stack(int m){
            max_size = m;
            arr = new int[m];
            top = 0;
        }
        void push(int data){
            if(top < max_size)
                arr[++top] = data;
            else
                cout << "Stack Full";
        }
        void pop(){
            if(top >= 0)
                top--;
            else
                cout << "Stack Empty";
        }
        int tos(){
            if(top >= 0)
                return arr[top--];
            else
                return -1;
        }
};
int main(){
    Stack st(5);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);
    cout << st.tos();
    st.pop();
    cout << st.tos();
}