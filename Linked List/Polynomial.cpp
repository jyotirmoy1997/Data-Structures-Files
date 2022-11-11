#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int degree;
    int coeff;
    int sign;
    Node *next;
    Node(int d, int c, int s)
    {
        degree = d;
        coeff = c;
        sign = s;
        next = NULL;
    }
};
Node* constructPolynomial(Node *header, int n)
{
    int c, s;
    Node *tail;
    while(n >= 0)
    {
        cout << "Enter co-efficient for degree - " << n << " :: ";
        cin >> c;
        cout << "Enter sign for degree - " << n << " :: ";
        cin >> s;
        if(header == NULL)
        {
            header = new Node(n, c, s);
            tail = header;
        }
        else
        {
            Node *temp = new Node(n, c, s);
            tail->next = temp;
            tail = temp;
        }
        n--;
    }
    return header;
}
void show(Node *header)
{
    Node *ptr = header;
    while(ptr != NULL)
    {
        if(ptr->sign == 1)
        {
            cout << ptr->coeff << "x^" << ptr->degree << " ";
        }
        else if(ptr->sign == -1)
        {
            cout << "-" << ptr->coeff << "x^" << ptr->degree << " ";
        }
        ptr = ptr->next;
    }
}
int main()
{
    Node *header = NULL;
    header = constructPolynomial(header, 3);
    show(header);
}