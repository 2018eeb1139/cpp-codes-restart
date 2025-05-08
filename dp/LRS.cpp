int LCS(string X, string Y)
{ // or call it --> int LRS(string X, string Y)

    int m = X.length();
    int n = Y.length();
    int dp[m + 1][n + 1];

    // initialization
    for (int i = 0; i <= m; i++)
        dp[i][0] = 0; // Eg LCS of "abc" & "" = 0
    for (int j = 0; j <= n; j++)
        dp[0][j] = 0; // Eg LCS of "" & "abc" = 0

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i - 1] == Y[j - 1] && i != j) // this is the only extra condition
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

void printLRS()
{

    string res = "";

    // Traverse dp[][] from bottom right
    int i = n, j = n;
    while (i > 0 && j > 0)
    {
        // If this cell is same as diagonally
        // adjacent cell just above it, then
        // same characters are present at
        // str[i-1] and str[j-1]. Append any
        // of them to result.
        if (dp[i][j] == dp[i - 1][j - 1] + 1)
        {
            res = res + str[i - 1];
            i--;
            j--;
        }

        // Otherwise we move to the side
        // that that gave us maximum result
        else if (dp[i][j] == dp[i - 1][j])
            i--;
        else
            j--;
    }

    // Since we traverse dp[][] from bottom,
    // we get result in reverse order.
    reverse(res.begin(), res.end());

    return res;
}