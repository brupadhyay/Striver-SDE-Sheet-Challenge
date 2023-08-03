#include <bits/stdc++.h> 
/**
 * TC - O(N)
 * SC - O(1)
*/


class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int prefix;
    int endCnt;

    TrieNode(char c){
        data = c;
        endCnt = 0;
        prefix = 0;
        for(int i = 0;i<26;i++){
            children[i] = NULL;
        }
    }
};



class Trie{

    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('#');
    }

    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0){
            root -> endCnt++;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if(root -> children[index] != NULL){
            child = root -> children[index];
        } else {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }

        child -> prefix++;
        insertUtil(child, word.substr(1));
    }

    void insert(string &word){
        insertUtil(root, word);
    }

    int countWordsEqualTo(string &word){
        TrieNode* curr = root;
        for(char c: word){
            int index = c - 'a';
            if(!curr -> children[index]) return 0;
            curr = curr -> children[index];
        }
        return curr -> endCnt;
    }

    int countWordsStartingWith(string &word){
        TrieNode* curr = root;
        for(char c: word){
            int index = c - 'a';
            if(!curr -> children[index]) return 0;
            curr = curr -> children[index];
        }
        return curr -> prefix;        
    }

    void erase(string &word){
        TrieNode* curr = root;
        for(char c: word){
            int index = c - 'a';
            if(!curr -> children[index]) return;
            curr = curr -> children[index];
            curr -> prefix--;
        }
        curr -> endCnt--;
    }
};
