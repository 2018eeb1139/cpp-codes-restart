vector<int> Solution::getRow(int k)
{
    if (k == 0)
        return {1};
    if (k == 1)
        return {1, 1};
    vector<vector<int>> ans(k + 1);
    for (int i = 0; i <= k; i++)
    {
        ans[i].resize(i + 1);
        for (int j = 0; j < i + 1; j++)
        {
            if (j == 0 || j == i)
                ans[i][j] = 1;
            else
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }
    return ans[k];
}