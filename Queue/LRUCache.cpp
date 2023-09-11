#include<bits/stdc++.h>
using namespace std;
class LRUCache 
{
    struct Node
    {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int k, int v)
        {
            key = k;
            val = v;
            next = NULL;
            prev = NULL;
        }
    };
    Node *head, *tail;
    int max_cap;
    unordered_map<int, Node*> mpp;
    public:
        LRUCache(int capacity) 
        {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            max_cap = capacity;
        }
        
        int get(int key) {
            if(mpp.find(key) != mpp.end()){
                Node* temp = mpp[key];
                int res = temp->val;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                mpp.erase(temp->key);
                free(temp);

                Node* newNode = new Node(key, res);
                newNode->next = head->next;
                head->next = newNode;
                newNode->next->prev = newNode;
                newNode->prev = head;
                mpp[key] = newNode;

                return res;
            }
            return -1;
        }
        void put(int key, int value) {
            if(mpp.find(key) != mpp.end()){
                    Node* temp = mpp[key];
                    temp->val = value;
            }
            else{
                if(mpp.size() < max_cap){
                        Node* newNode = new Node(key, value);
                        newNode->next = head->next;
                        head->next = newNode;
                        newNode->next->prev = newNode;
                        newNode->prev = head;
                        mpp[key] = newNode;
                }
                else{
                    // Delete LRU Item
                    Node* temp = tail->prev;
                    mpp.erase(temp->key);
                    tail->prev = temp->prev;
                    temp->prev->next = tail;
                    free(temp);

                    // Insert New Item after head
                    Node* newNode = new Node(key, value);
                    newNode->next = head->next;
                    head->next = newNode;
                    newNode->next->prev = newNode;
                    newNode->prev = head;
                    mpp[key] = newNode;
                }
            }
        }
};
int main(){
    LRUCache lr(3);
    lr.put(3, 10);
    lr.put(2, 11);
    cout << lr.get(1);
    lr.put(1, 13);
}