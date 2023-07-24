#include <bits/stdc++.h> 
/**
 * Using two for loops
 * TC - O(n*m)
 * SC - O(1)
*/
bool areAnagram(string &str1, string &str2){
    int n = str1.length(), m = str2.length();
    for(int i = 0;i<n;i++){
        int occ = 0;
        for(int j = 0;j<m;j++){
            if(str2[j] == str1[i]) occ++;
        }
        if(occ == 0) return false;
    }
    return true;
}

/**
 * Using frequency array
 * TC - O(n + 26) ~ O(n)
 * SC - O(26) ~ O(1)
*/

bool areAnagram(string &str1, string &str2){
    int n = str1.length(), m = str2.length();

    if(n != m) return 0;

    int freq[26] = {0};

    for(int i = 0;i<n;i++){
        freq[str1[i] - 'a']++;
        freq[str2[i] - 'a']--;
    }

    for(int i = 0;i<26;i++){
        if(freq[i] > 0) return false;
    }

    return true;
}