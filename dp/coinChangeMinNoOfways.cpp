int coinChange(vector<int> &coins, int sum)
{
    int n = coins.size();
    vector<vector<int>> t(n + 1, vector<int>(sum + 1));
    for (int j = 0; j < sum + 1; j++)
    {
        t[0][j] = INT_MAX - 1;
    }
    for (int i = 1; i < n + 1; i++)
    {
        t[i][0] = 0;
    }
    for (int j = 1; j < sum + 1; j++)
    {
        t[1][j] = (j % coins[0] == 0 ? (j / coins[0]) : INT_MAX - 1);
    }
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (coins[i - 1] <= j)
            {
                t[i][j] = min(t[i - 1][j], 1 + t[i][j - coins[i - 1]]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return (t[n][sum] == INT_MAX - 1 ? -1 : t[n][sum]);
}