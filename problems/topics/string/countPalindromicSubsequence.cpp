/*
Palindromic Subsequence Count - Dynamic Programming Approach

A palindromic subsequence is a sequence of characters that remains the same even when read in reverse order. Given a string, the task is to find the number of palindromic subsequences present in it. This problem can be solved using dynamic programming.

Approach

Let dp[i][j] be the count of palindromic subsequences in the substring str[i...j]. If the length of the substring is 1, then it is a palindromic subsequence itself. So, dp[i][i] = 1.

Now, we build the matrix dp in diagonal fashion. For each length cl (starting from 2), we consider all substrings of length cl and compute the count of palindromic subsequences for each of them. We fill up the dp matrix diagonally using the following recurrence relation:

if (str[i] == str[j])
dp[i][j] = dp[i][j - 1] + dp[i + 1][j] + 1;
else
dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];

Here, dp[i][j - 1] and dp[i + 1][j] represent the count of palindromic subsequences in the substrings str[i...(j-1)] and str[(i+1)...j], respectively. We add 1 to account for the palindromic subsequence consisting of just the characters str[i] and str[j]. If str[i] and str[j] are not equal, then we need to subtract dp[i + 1][j - 1] because we have double-counted the palindromic subsequences consisting of str[i] and str[j]. We also need to take the modulo 109+7 to prevent overflow.

Finally, the count of palindromic subsequences in the whole string is dp[0][n-1], where n is the length of the string.

Implementation in C++

Here is the C++ implementation of the above approach:
*/
#define mod 1000000007

int countPs(string str)
{
    int n = str.length();

    // Create a 2D array to store the count of palindromic subsequence
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    // Every single character is a palindromic subsequence
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    // Build the matrix in diagonal fashion
    for (int cl = 2; cl <= n; cl++)
    {
        for (int i = 0; i < n - cl + 1; i++)
        {
            int j = i + cl - 1;
            if (str[i] == str[j])
                dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] + 1) % mod;
            else
                dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + mod) % mod;
        }
    }

    // Return the count of palindromic subsequence
    return dp[0][n - 1];
}

/*
Time and Space Complexity

The time complexity of this algorithm is O(N^2), where N is the length of the string. The space complexity is also O(N^2) because we
*/