#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Queue
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
    Node *header, *tail;
    public:
        Queue()
        {
            header = NULL;
            tail = NULL;
        }
        void enqueue(T val)
        {
            if(header == NULL)
            {
                header = new Node(val);
                tail = header;
            }
            else
            {
                Node *temp = new Node(val);
                tail->next = temp;
                tail = temp;
            }
        }
        void dequeue()
        {
            if(header != NULL)
            {
                Node *temp = header;
                header = header->next;
                free(temp);
            }
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
    Queue<int> q;
    q.enqueue(2);
    q.enqueue(4);
    q.enqueue(9);
    q.enqueue(3);
    q.dequeue();
    q.enqueue(10);
    q.show();
}