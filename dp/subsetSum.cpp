#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <unordered_set>
#include <set>

int dp[205][40005];
bool func(int idx, int target, vector<int> &arr)
{
    if (target == 0)
        return true;
    if (idx < 0)
        return false;
    if (dp[idx][target] != -1)
        return dp[idx][target];
    bool ispos = func(idx - 1, target, arr);
    if (target - arr[idx - 1] >= 0)
    {
        ispos |= func(idx - 1, target - arr[idx - 1], arr);
    }
    return dp[idx][target] = ispos;
}

bool isSubsetSum(vector<int> &arr, int target)
{
    // code here
    memset(dp, -1, sizeof(dp));
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < target + 1; j++)
        {
            if (j - arr[i - 1] >= 0)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][target];
    return func(n, target, arr);
}