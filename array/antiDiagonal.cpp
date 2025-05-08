vector<vector<int>> Solution::diagonal(vector<vector<int>> &A)
{
    int n = A.size();
    vector<vector<int>> res((2 * n) - 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int idx = i + j;

            res[idx].push_back(A[i][j]);
        }
    }
    return res;
}
