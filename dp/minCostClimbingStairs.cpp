int n;
int t[1001];
int solve(int i, vector<int> &cost)
{
    if (i >= n)
    {
        return 0;
    }
    if (t[i] != -1)
        return t[i];
    int one_step = cost[i] + solve(i + 1, cost);
    int two_step = cost[i] + solve(i + 2, cost);

    return t[i] = min(one_step, two_step);
}

int minCostClimbingStairs(vector<int> &cost)
{
    memset(t, -1, sizeof(t));
    n = cost.size();
    return min(solve(0, cost), solve(1, cost));
}