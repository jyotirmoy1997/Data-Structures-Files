#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Stack
{
    struct Node
    {
        T data;
        Node *next;
        Node(T val)
        {
            data = val;
            next = NULL;
        }
    };
    Node *header;
    public:
        Stack()
        {
            header = NULL;
        }
        void push(T data)
        {
            if(header == NULL)
            {
                header = new Node(data);
            }
            else
            {
                Node *temp = new Node(data);
                temp->next = header;
                header = temp;
            }
        }
        void pop()
        {
            if(header != NULL)
            {
                Node *ptr = header;
                header = header->next;
                free(ptr);
            }
        }
        T top()
        {
            return header->data;
        }
        void show()
        {
            Node *ptr = header;
            while(ptr != NULL)
            {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
        }

};
int main()
{
    Stack<int> st;
    st.push(6);
    st.push(7);
    st.push(1);
    st.push(4);
    st.push(9);
    st.pop();
    st.push(10);
    cout << st.top() << endl;
    st.show();
}