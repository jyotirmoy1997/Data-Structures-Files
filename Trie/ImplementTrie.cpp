#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch){
        // If the character is present, then the array index will point to a reference.
        // If the character is not present, then the array index will point to NULL.
        // Example : ch = b (98) and a = 97. Then ch - 'a' will be 1 which is the desired index of b.
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};
class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                // If the character is not present, we create a new node reference.
                node->put(word[i], new Node());
            }

            // After putting the word, move the node to the next reference node
            node = node->get(word[i]);
        }
        // After the word is inserted into the trie, set the last refernce node to true indicating that 
        // the word is complete
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            // If the character does not exist in the trie, then return false;
            if(!node->containsKey(word[i]))
                return false;

            node = node->get(word[i]);
        }

        // After the string is exhausted, return the value of flag.
        // If it is true, then the word exists, if false, then the word does not exist.
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.length(); i++){
            // If the character does not exist in the trie, then return false;
            if(!node->containsKey(prefix[i]))
                return false;

            node = node->get(prefix[i]);
        }

        // After the string is exhausted, return true as we found that the prefix exist.
        return true;
    }
};
int main()
{
	int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (trie.startsWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
}