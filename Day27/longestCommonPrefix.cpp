#include <bits/stdc++.h> 
/**
 * TC - O(n x m)
 * SC - O(n x m)
*/
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childCount;

    TrieNode(char c){
        data = c;
        for(int i = 0;i<26;i++){
            children[i] = NULL;
        }
        childCount = 0;
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
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if(root -> children[index] != NULL){
            child = root -> children[index];
        } else {
            child = new TrieNode(word[0]);
            // new node so child count increases
            root -> childCount++;
            root -> children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insert(string &word){
        insertUtil(root, word);
    }
    
    void lcp(string &ans){
        TrieNode* curr = root;
        // if child count is 1 then append
        while(curr && curr -> childCount == 1){
            TrieNode* child = NULL;
            for(int i = 0;i<26;i++){
                if(curr -> children[i] != NULL){
                    child = curr -> children[i];
                    break;
                }
            }
            // node -> data and move curr to child
            ans += child -> data;
            curr = child;
        }
    }
    
};


string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie t;
    for(auto &s: arr){
        t.insert(s);
    }
    string ans;
    t.lcp(ans);
    return ans;
}


/**
 * OPTIMUM APPROACH
 * TC - O(n x m)
 * SC - O(1)
*/

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    for(int i = 0;i<arr[0].size();i++){
        char curr = arr[0][i];
        for(int j = 1;j<n;j++){
            if(curr != arr[j][i]) return ans;
        }
        ans += curr;
    }
    return ans;
}


