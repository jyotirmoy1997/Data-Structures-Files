#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node *links[26];
    int countPrefix = 0;
    int countEndsWith = 0;
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void increaseEnd(){
        countEndsWith++;
    }

    void increasePrefix(){
        countPrefix++;
    }

    void deleteEnd(){
        countEndsWith--;
    }

    void reducePrefix(){
        countPrefix--;
    }

    int getEnd(){
        return countEndsWith;
    }

    int getPrefix(){
        return countPrefix;
    }
};
class Trie{
    private :
        Node *root;
    public:

    Trie(){
        root = new Node();
    }

    void insert(string &word){
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);

            // Inrement the prefix of value by 1 which indicates that there exists
            // a word that has the desired prefix.
            node->increasePrefix();
        }
        // Inrement the end of value by 1 which indicates that there exists
        // a word which matches the desired word in the trie.
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getPrefix();
    }

    void erase(string &word){
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else
                return;
        }
        node->deleteEnd();
    }
};

