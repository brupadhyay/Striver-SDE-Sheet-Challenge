#include <set>
/**
 * Using set
 * TC - O(n^2log(k)) where k is no.of substrings generated
 * SC - O(k)
*/
int countDistinctSubstrings(string &s)
{
    set<string> st;
    int n = s.size();
    for(int i = 0;i<n;i++){
        string temp= "";
        for(int j = i;j<n;j++){
            temp += s[j];
            st.insert(temp);
        }
    }
    return st.size() + 1;
}

/**
 * USING TRIE
 * TC - O(n^2)
 * SC - O(n^2) { depends on the input given }
*/

struct Trie{
    Trie *links[26];

    Trie* containsKey(char c){
        return links[c - 'a'];
    }

    Trie* get(char c){
        return links[c - 'a'];
    }

    void put(char c, Trie* node){
        links[c - 'a'] = node;
    }
};

int countDistinctSubstrings(string &s)
{
    Trie* root = new Trie();
    int n = s.size();
    int cnt = 0;
    for(int i = 0;i<n;i++){
        Trie* node = root;
        for(int j = i;j<n;j++){
            if(!node -> containsKey(s[j])){
                node -> put(s[j], new Trie());
                cnt++;
            }
            node = node -> get(s[j]);
        }
    }
    return cnt + 1;
}