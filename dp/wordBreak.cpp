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