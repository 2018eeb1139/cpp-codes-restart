
int Solution::solve(vector<vector<int>> &A)
{
    int m = A.size();
    int n = A[0].size();

    vector<vector<int>> t(m, vector<int>(n));
    int ans = 1; // minimum can be 1 sub size square matrix
    for (int j = 0; j < n; j++)
    {
        if (A[0][j] == 1)
        {
            t[0][j] = 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (A[i][0] == 1)
        {
            t[i][0] = 1;
        }
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (A[i][j] == 1)
            {
                t[i][j] = min({t[i - 1][j - 1], t[i - 1][j], t[i][j - 1]}) + 1;
            }
            else
            {
                t[i][j] = 0;
            }
            ans = max(ans, t[i][j]);
        }
    }
    return ans * ans;
}
