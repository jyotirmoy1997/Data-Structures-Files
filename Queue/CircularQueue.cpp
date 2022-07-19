#include<bits/stdc++.h>
using namespace std;
class Queue
{
    int max;
    int *queue;
    int front, rear;
    public:
        Queue(int size)
        {
            max = size;
            queue = new int[max];
            front = -1;
            rear = -1;
        }
        void enqueue(int val)
        {
            if(front == -1 && rear == -1)
            {
                front = 0;
                rear = 0;
                queue[rear] = val;
            }
            else if((rear + 1) % max == front)
            {
                cout << "Queue is Full";
            }
            else
            {
                rear = (rear + 1) % max;
                queue[rear] = val;
            }
        }
        void dequeue()
        {
            if(front == -1 && rear == -1)
            {
                cout << "Queue is Empty";
            }
            else if(front == rear)
            {
                cout << "Element :: " << queue[front];
                front = -1;
                rear = -1;
            }
            else
            {
                cout << "Element :: " << queue[front];
                front = (front + 1) % max;
            }
            cout << endl;
        }
        void display()
        {
            if(front == -1 && rear == -1)
            {
                cout << "Queue is empty";
            }
            else
            {
                int i = front;
                cout << "Elements in the queue are :: " << endl;
                do
                {
                    cout << queue[i] << " ";
                    i++;
                } while (i <= rear);        
            }
            cout << endl;
        }
};
int main()
{
    Queue q(8);
    q.enqueue(10);
    q.enqueue(8);
    q.enqueue(11);
    q.enqueue(6);
    q.enqueue(13);
    q.enqueue(56);
    q.enqueue(97);
    q.enqueue(15);
    q.display();
    q.dequeue();
    q.display();
}