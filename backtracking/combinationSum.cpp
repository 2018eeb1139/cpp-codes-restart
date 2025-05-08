void solve(int start, int n, vector<int> &v, vector<int> &candidates, int target, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(v);
        return;
    }
    for (int i = start; i < n; i++)
    {
        if (candidates[i] <= target)
        {
            v.push_back(candidates[i]);
            solve(i, n, v, candidates, target - candidates[i], ans);
            v.pop_back();
        }
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    int n = candidates.size();
    vector<int> v;
    solve(0, n, v, candidates, target, ans);
    return ans;
}