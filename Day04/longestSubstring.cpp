/*brute force
using two loops and maintain a set for unique characters
once duplicate is found find max and break and start again from next ith index
else keep on inserting into set
TC - O(N^2)
SC - O(N)
*/

#include <bits/stdc++.h>
using namespace std;
int uniqueSubstrings(string input)
{
    int maxi = 1;

    int n = input.length();
    for (int i = 0; i < n; i++)
    {
        set<char> st;
        for (int j = i; j < n; j++)
        {
            if (st.find(input[j]) == st.end())
            {
                st.insert(input[j]);
            }
            else
            {
                maxi = max(maxi, (int)st.size());
                break;
            }
        }
    }
    return maxi;
}

/* optimal approach 1 -

TC - O(2*N)
SC - O(n)
*/
int uniqueSubstrings(string input)
{
    int maxi = 1;
    int freq[256] = {0};

    int n = input.length();
    int l = 0, r = 0;
    while (r < n)
    {
        while (l < r && freq[input[r]] > 0)
        {
            freq[input[l]]--;
            l++;
        }
        maxi = max(maxi, r - l + 1);
        freq[input[r]]++;
        r++;
    }
    return maxi;
}

/*
optimal approach 2
TC - O(n)
SC - O(n)*/

int uniqueSubstrings(string input)
{
    int maxi = 1;
    int freq[256];
    memset(freq, -1, sizeof freq);

    int n = input.size();
    int l = 0, r = 0;
    while (r < n)
    {
        if (freq[input[r]] != -1)
        {
            // we directly point left to the previous duplicate index + 1
            l = max(freq[input[r]] + 1, l);
        }
        maxi = max(maxi, r - l + 1);
        freq[input[r]] = r;
        r++;
    }
    return maxi;
}

int main()
{
    string input = "brupadhyay";
    cout << "longest substring w/o repeating character is " << uniqueSubstrings(input);
}