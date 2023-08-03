/**
 * Using bit manipulation
 * checking if ith bit is set then append character
 * TC - O(2^n*n) 
 * Reason: O(2^n) for the outer for loop and O(n) for the inner for loop.
 * SC - O(1)
 */

/*
    s = abc

    n   c b a  substr
    0   0 0 0   ""
    1   0 0 1   "a"
    2   0 1 0   "b"
    3   0 1 1   "ab"
    4   1 0 0   "c"
    5   1 0 1   "ac"
    6   1 1 0   "bc"
    7   1 1 1   "abc"

    for example n = 7
    i = 0 so (7 & (1 << 0)) = (7 & 1) = 1 so path = "a"
    i = 1 so (7 & (1 << 1)) = (7 & 1) = 1 so path = "ab"
    i = 2 so (7 & (1 << 2)) = (7 & 4) = 1 so path = "abc"
*/

vector<string> AllPossibleStrings(string s)
{
    vector<string> ans;
    int n = s.size();

    for (int num = 0; num < pow(2, n); num++)
    {
        string temp = "";
        for (int i = 0; i < n; i++)
        {

            if (num & (1 << i))
            {
                temp += s[i];
            }
        }
        if (temp.size())
        {
            ans.push_back(temp);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}

/**
 * TC - O(2^n)
 * SC - O(n) { recursive stack space }
 */

void permute(int i, string s, string path, vector<string> &ans)
{
    if (i >= s.size())
    {
        if (path.size())
            ans.push_back(path);
        return;
    }

    permute(i + 1, s, path + s[i], ans);
    permute(i + 1, s, path, ans);
}

vector<string> AllPossibleStrings(string s)
{
    vector<string> ans;
    permute(0, s, "", ans);
    sort(ans.begin(), ans.end());
    return ans;
}