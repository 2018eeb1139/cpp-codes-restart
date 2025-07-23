// recursive

bool wordBreak(string s, vector<string> &wordDict)
{
    if (s.size() == 0)
        return true;
    int n = s.size();
    for (int i = 1; i <= n; i++)
    {
        string prefix = s.substr(0, i);
        if (wordDict.find(wordDict.begin(), wordDict.end(), prefix) != wordDict.end() &&
            wordBreak(s.substr(i)))
        {
            return true;
        }
    }
    return false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    if (s.size() == 0)
        return true;
    int n = s.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    unordered_set<string> word(wordDict.begin(), wordDict.end());
    for (int j = 1; j <= n; j++)
    {
        for (int i = 0; i < j; i++)
        {
            if (dp[i] && word.find(s.substr(i, j - i)) != word.end())
            {
                dp[j] = true;
                break;
            }
        }
    }
    return dp[n];
}
// RECUR+MEMO
unordered_set<string> st;
int t[301];
bool solve(int idx, int n, string s)
{
    if (idx >= n)
    {
        return true;
    }
    if (t[idx] != -1)
        return t[idx];
    if (st.find(s) != st.end())
    {
        return t[idx] = true;
    }
    for (int l = 1; l <= n; l++)
    {
        string temp = s.substr(idx, l);
        if (st.find(temp) != st.end() && solve(idx + l, n, s))
        {
            return t[idx] = true;
        }
    }
    return t[idx] = false;
}
bool wordBreak(string s, vector<string> &wordDict)
{
    int n = s.size();
    memset(t, -1, sizeof(t));
    for (auto &word : wordDict)
    {
        st.insert(word);
    }
    return solve(0, n, s);
}