int t[201][1001];
int solve(int idx, int n, vector<int> &nums, int target)
{
    if (target == 0)
        return 1;
    if (idx >= n || target < 0)
        return 0;
    if (t[idx][target] != -1)
        return t[idx][target];
    int take = solve(0, n, nums, target - nums[idx]);
    int notTake = solve(idx + 1, n, nums, target);
    return t[idx][target] = take + notTake;
}
int combinationSum4(vector<int> &nums, int target)
{
    memset(t, -1, sizeof(t));
    int n = nums.size();
    return solve(0, n, nums, target);
}