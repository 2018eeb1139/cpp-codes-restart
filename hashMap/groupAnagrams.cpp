vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    int n = strs.size();
    if (n == 0)
        return {{}};
    if (n == 1)
        return {{strs[0]}};
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> m;
    for (int i = 0; i < n; i++)
    {
        string s = strs[i];
        sort(strs[i].begin(), strs[i].end());
        if (m.find(strs[i]) == m.end())
        {
            m[strs[i]].push_back(s);
        }
        else
        {
            m[strs[i]].push_back(s);
        }
    }
    for (auto x : m)
    {
        vector<string> v = x.second;
        ans.push_back(v);
    }
    return ans;
}