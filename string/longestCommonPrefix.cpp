string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    if (n == 0)
        return "";
    if (n == 1)
        return strs[0];
    string prefix = strs[0];
    for (int i = 1; i < n; i++)
    {
        string curr = strs[i];
        int sz = min(curr.size(), prefix.size());
        string ans = "";
        for (int j = 0; j < sz; j++)
        {
            if (curr[j] == prefix[j])
            {
                ans += prefix[j];
            }
            else
            {
                break;
            }
        }
        prefix = ans;
    }
    return prefix;
}