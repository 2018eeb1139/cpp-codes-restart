vector<vector<int>> Solution::anagrams(const vector<string> &A)
{
    int n = A.size();
    unordered_map<string, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
        string s = A[i];
        sort(s.begin(), s.end());
        m[s].push_back(i + 1);
    }
    vector<vector<int>> ans;
    for (auto &x : m)
    {
        ans.push_back(x.second);
    }
    return ans;
}
