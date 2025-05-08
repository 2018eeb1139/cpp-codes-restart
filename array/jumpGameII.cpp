// recursive + memoized
#include <iostream>
#include <vector>
using namespace std;

int dp[10001][10001];
int solve(int idx, int jumps, int n, vector<int> &nums)
{
    if (idx >= n - 1)
        return jumps;
    if (dp[idx][jumps] != -1)
        return dp[idx][jumps];
    int mn = INT_MAX;
    for (int i = 1; i <= nums[idx]; i++)
    {
        mn = min(mn, solve(idx + i, jumps + 1, n, nums));
    }
    return dp[idx][jumps] = mn;
}
int jump(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return 0;
    if (nums[0] == 0)
        return 0;
    memset(dp, -1, sizeof(dp));
    int idx = 0, jumps = 0;
    return solve(idx, jumps, n, nums);
}

int jump(vector<int> &nums)
{
    int curr = 0;
    int maxIdx = 0;
    int jumps = 0;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (i + nums[i] > maxIdx)
            maxIdx = i + nums[i];
        if (i == curr)
        {
            jumps++;
            curr = maxIdx;
        }
    }
    return jumps;
}