#include<bits/stdc++.h>
using namespace std;
struct Node{
    int key, val, count;
    Node *next;
    Node *prev;
    Node(int k, int v){
        key = k;
        val = v;
        count = 1;
    }
};
struct List{
    int size;
    Node *head;
    Node *tail;
    List(){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node *newNode){
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
        size++;
    }
    void removeNode(Node *delNode){
        Node* prevNode = delNode->prev;
        Node* nxtNode = delNode->next;
        prevNode->next = nxtNode;
        nxtNode->prev = prevNode;
        size--;
    }
};
class LFUCache {
    int max_cap;
    int min_frq;
    int curr_size;
    unordered_map<int, List*> frqList;
    unordered_map<int, Node*> mpp;
    public:
        LFUCache(int capacity) {
            max_cap = capacity;
            min_frq = 0;
            curr_size = 0;
        }
        void updateFrqList(Node *node){
            mpp.erase(node->key);
            List *currList = frqList[node->count];
            currList->removeNode(node);
            if(node->count == min_frq && frqList[node->count]->size == 0)
                min_frq++;
            
            List *nextHigherFrqList = new List();
            if(frqList.find(node->count + 1) != frqList.end())
                nextHigherFrqList = frqList[node->count + 1];
            
            node->count += 1;
            nextHigherFrqList->addFront(node);
            frqList[node->count] = nextHigherFrqList;
            mpp[node->key] = node;
        }
        int get(int key) {
            if(mpp.find(key) != mpp.end()){
                Node *temp = mpp[key];
                int val = temp->val;
                updateFrqList(temp);
                return val;
            }
            return -1;
        }
        void put(int key, int value) {
            if(max_cap == 0)
                return;

            if(mpp.find(key) != mpp.end()){
                Node *temp = mpp[key];
                temp->val = value;
                updateFrqList(temp);
            }
            else{
                if(curr_size == max_cap){
                    List *list = frqList[min_frq];
                    mpp.erase(list->tail->prev->key);
                    frqList[min_frq]->removeNode(list->tail->prev);
                    curr_size--;
                }
                curr_size++;
                min_frq = 1;
                List *listFrq = new List();
                if(frqList.find(min_frq) != frqList.end())
                    listFrq = frqList[min_frq];
                
                Node *node = new Node(key, value);
                listFrq->addFront(node);
                mpp[key] = node;
                frqList[min_frq] = listFrq;
            }
            
        }
};
int main(){
    
}