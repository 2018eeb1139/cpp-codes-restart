vector<vector<int>> dp;
int func(int index, int amount, vector<int> &coins)
{
    if (amount == 0)
        return 1;
    if (index < 0)
        return 0;

    if (dp[index][amount] != -1)
        return dp[index][amount];

    int ans = func(index - 1, amount, coins);
    if (amount - coins[index] >= 0)
    {
        ans += func(index, amount - coins[index], coins);
    }

    return dp[index][amount] = ans;
}

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    dp.assign(n + 1, vector<int>(amount + 1, -1));
    return func(n - 1, amount, coins);
}

int count(vector<int> &coins, int amount)
{
    // code here.
    int n = coins.size();
    vector<vector<long long>> t(n + 1, vector<long long>(amount + 1, 0));
    for (int j = 0; j < amount + 1; j++)
    {
        t[0][j] = 0;
    }
    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 1;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < amount + 1; j++)
        {
            // if(j-coins[i-1]<0) t[i-1][j] + 0;
            if (j - coins[i - 1] >= 0)
            {

                t[i][j] = t[i - 1][j] + t[i][j - coins[i - 1]];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][amount];
}