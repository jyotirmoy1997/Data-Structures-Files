#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node *links[26];
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
};
int countDistinctSubstrings(string &s){
    Node* root = new Node();
    int count = 0, l = s.length();
    for(int i=0; i<l; i++){
        Node* node = root;
        for(int j=i; j<l; j++){
            if(!node->containsKey(s[j])){
                node->put(s[j], new Node());
                count++;
            }
            node = node->get(s[j]);
        } 
    }
    return count + 1;
}
int main(){
    string s = "abab";
    cout << countDistinctSubstrings(s);
}