int editDistance(string s1, string s2, int m, int n)
{
    if (m == 0)
    {
        return n;
    }
    if (n == 0)
    {
        return m;
    }
    if (s1[m - 1] == s2[n - 1])
    {
        return editDistance(s1, s2, m - 1, n - 1);
    }
    else
    {
        return 1 + min(editDistance(s1, s2, m - 1, n),
                       min(editDistance(s1, s2, m, n - 1),
                           editDistance(s1, s2, m - 1, n - 1)));
    }
}

int Solution::minDistance(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> t(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++)
        t[i][0] = i;
    for (int j = 0; j <= n; j++)
        t[0][j] = j;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                t[i][j] = t[i - 1][j - 1];
            else
                t[i][j] = 1 + min({t[i][j - 1],
                                   t[i - 1][j],
                                   t[i - 1][j - 1]});
        }
    }

    return t[m][n];
}
