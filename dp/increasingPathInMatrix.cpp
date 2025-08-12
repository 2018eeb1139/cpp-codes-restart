int Solution::solve(vector<vector<int>> &A)
{
    int m = A.size();
    int n = A[0].size();

    vector<vector<int>> t(m, vector<int>(n, 0));
    t[0][0] = 1;

    for (int j = 1; j < n; j++)
    {
        if (A[0][j] > A[0][j - 1] && t[0][j - 1] != 0)
        {
            t[0][j] = 1 + t[0][j - 1];
        }
    }
    for (int i = 1; i < m; i++)
    {
        if (A[i][0] > A[i - 1][0] && t[i - 1][0] != 0)
        {
            t[i][0] = 1 + t[i - 1][0];
        }
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (A[i][j] > A[i - 1][j] && t[i - 1][j] != 0)
            {
                t[i][j] = max(t[i][j], 1 + t[i - 1][j]);
            }
            if (A[i][j] > A[i][j - 1] && t[i][j - 1] != 0)
            {
                t[i][j] = max(t[i][j], 1 + t[i][j - 1]);
            }
        }
    }
    return t[m - 1][n - 1] == 0 ? -1 : t[m - 1][n - 1];
}
