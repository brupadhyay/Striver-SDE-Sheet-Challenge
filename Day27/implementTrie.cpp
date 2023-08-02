#include <iostream>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    // parameterized constructor 
    TrieNode(char c){
        data = c;
        for(int i = 0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    // constructor
    Trie(){
        root = new TrieNode('#');
    }

    // *O(L) where L is length of word
    void insertUtil(TrieNode* root, string toBeInserted){
        // base case
        if(toBeInserted.length() == 0){
            root -> isTerminal = true;
            return;
        }

        int indexToInsert = toBeInserted[0] - 'a';
        TrieNode* child;
        // present
        if(root -> children[indexToInsert] != NULL){
            child = root -> children[indexToInsert];
        } else {
            // absent
            child = new TrieNode(toBeInserted[0]);
            root -> children[indexToInsert] = child;
        }

        // recursive call
        insertUtil(child, toBeInserted.substr(1));
    }

    // *O(L) where L is length of word
    void removeUtil(TrieNode* root, string word){
        for(char c: word){
            int index = c - 'a';
            root = root -> children[index];
        }
        root -> isTerminal = false;
    }

    // *O(L) where L is length of word
    bool searchUtil(TrieNode* root, string toBeSearched){
        // base case
        if(toBeSearched.length() == 0){
            return root -> isTerminal;
        }

        TrieNode* child;
        int index = toBeSearched[0] - 'a';
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else {
            // return false if absent
            return false;
        }

        // recursive call
        return searchUtil(child, toBeSearched.substr(1));
    }
    // *O(L) where L is length of word
    bool startsUtil(TrieNode* curr, string prefix){
        for(char c: prefix){
            int index = c - 'a';
            if(curr -> children[index] == NULL){
                return false;
            }
            curr = curr -> children[index];
        }
        return true;
    }

    void insertWord(string toBeInserted){
        insertUtil(root, toBeInserted);
    }

    bool searchWord(string toBeSearched){
        return searchUtil(root, toBeSearched);
    }

    bool startsWith(string prefix){
        return startsUtil(root, prefix);
    }

    void removeWord(string word){
        removeUtil(root, word);
    }

};


int main(){
    Trie t;
    t.insertWord("apple");
    t.insertWord("append");

    cout << "searching for words : " << endl;
    t.searchWord("app") ?  cout << "true" : cout << "false" << endl;
    t.searchWord("apple") ?  cout << "true" : cout << "false" << endl;

    cout << "\ndoes trie has prefix: " << endl;
    t.startsWith("apd") ? cout << "true" : cout << "false" << endl;
    t.startsWith("apple") ? cout << "true" : cout << "false" << endl;

    t.removeWord("apple");
    cout << "\nSearch for apple: "<< endl;
    t.searchWord("apple") ?  cout << "true" : cout << "false" << endl;

    return 0;
}
