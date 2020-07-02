#include<bits/stdc++.h>

using namespace std;

const int ALPHA_SZ = 27;
const int MAX_NODE = 500500;

class Trie {

private:

    struct TrieNode {
        char val;
        int count;
        int endHere;
        TrieNode* child[ALPHA_SZ];
    };

    TrieNode* root;

    TrieNode* createNode(int value) {
        
        TrieNode* newNode = new TrieNode();
        
        newNode->val = 'a' + value;
        newNode->count = 0;
        newNode->endHere = 0;
        
        for(int i = 0; i < ALPHA_SZ; ++i) {
            newNode->child[i] = NULL;
        }
        return newNode;
    } 

public:

    Trie() { root = createNode('/' - 'a'); }

    void insert(string word) {
        
        TrieNode* curr = root;

        for(int i = 0; i < (int)word.size(); ++i) {
            
            int value = word[i] - 'a';
            
            if (curr->child[value] == NULL)
                curr->child[value] = createNode(value);
            
            curr->child[value]->count += 1;
            curr = curr->child[value];
        }

        curr->endHere += 1;
    }

    bool search(string word) {
        
        TrieNode* curr = root;

        for(int i = 0; i < (int)word.size(); ++i) {
            int value = word[i] - 'a';
            if (curr->child[value] == NULL)
                return false;
            curr = curr->child[value];
        }

        return (curr->endHere > 0);

    }

    bool startWith(string prefix) {
        
        TrieNode* curr = root;

        for(int i = 0; i < (int)prefix.size(); ++i) {
            int value = prefix[i] - 'a';
            if (curr->child[value] == NULL)
                return false;
            curr = curr->child[value];
        }

        return (curr->count > 0);
    }

};

int main() {
    
    Trie* myTrie = new Trie();
        
    string s;
    cin >> s;

    myTrie->insert(s);

    string p;
    cin >> p;

    if (myTrie->search(p))
        cout << "found p in the trie" << '\n';

    if (myTrie->startWith(p))
        cout << "the trie has a prefix with p" << '\n';


    return 0;   
}
