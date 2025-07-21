#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return true;
    if (nums[0] == 0)
        return false;
    int maxIdx = 0; // starting at idx 0
    for (int i = 0; i < n; i++)
    {
        if (i > maxIdx)
            return false;
        maxIdx = max(maxIdx, i + nums[i]);
    }
    return true;
}

// Recur + MEMO
int dp[10001];
bool solve(vector<int> &nums, int i, int n)
{
    if (dp[i] != -1)
        return dp[i];
    if (i >= n - 1)
        return dp[i] = true;
    for (int j = 1; j <= nums[i]; j++)
    {
        if (solve(nums, i + j, n))
        {
            return dp[i] = true;
        }
    }
    return dp[i] = false;
}
bool canJump(vector<int> &nums)
{
    memset(dp, -1, sizeof(dp));
    int n = nums.size();
    return solve(nums, 0, n);
}