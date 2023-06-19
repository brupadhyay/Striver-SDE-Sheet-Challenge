/* GOOGLE INTERVIEW QUESTION
BRUTE FORCE - recursion try out all possible paths and check if we can reach target
TC - exponential
SC - exponential
*/

#include <iostream>
#include <vector>
using namespace std;

int countPaths(int i, int j, int n, int m)
{
    if (i == (n - 1) && j == (m - 1))
        return 1;
    if (i >= n || j >= m)
        return 0;
    else
        return countPaths(i + 1, j, n, m) + countPaths(i, j + 1, n, m);
}

int uniquePaths(int m, int n)
{
    return countPaths(0, 0, m, n);
}

/*
better approach - using dp as hashing (overlapping sub problems)
TC - O(m x n)
SC - O(m x n)
*/

int countPaths(int i, int j, int n, int m, vector<vector<int>> &dp)
{
    if (i == (n - 1) && j == (m - 1))
        return 1;
    if (i >= n || j >= m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    else
        return dp[i][j] = countPaths(i + 1, j, n, m, dp) + countPaths(i, j + 1, n, m, dp);
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    countPaths(0, 0, m, n, dp);
    if (n == 1 && m == 1)
        return 1;
    return dp[0][0];
}

/*
 * OPTIMAL APPROACH - we need an m+n-2 number of steps to reach the end among those steps if we choose n-1 rightward direction or m-1 downward direction and calculate the combinations ( ie: m+n-2Cn-1 or m+n-2Cm-1) we’ll get the total number of paths.

 ? m - 1 steps and n - 1 steps each time so m + n - 2

 * TC - O(m-1) or O(n-1) depending on the formula we use
 * SC - O(1)
*/

int uniquePaths(int n, int m)
{
    int N = m + n - 2;
    int r = m - 1;
    int ans = 1;
    // * 3C2 = 3 x 2/ 1 x 2
    for (int i = 1; i <= r; i++)
    {
        ans *= (N - i + 1);
        ans /= (i);
    }
    return ans;
}

int main()
{
    int totalCount = uniquePaths(2, 3);
    cout << "The total number of Unique Paths are " << totalCount << endl;
}
