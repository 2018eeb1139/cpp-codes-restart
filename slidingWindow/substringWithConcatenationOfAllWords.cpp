vector<int> findSubstring(string s, vector<string> &words)
{
    vector<int> ans;
    if (s.size() == 0 || words.size() == 0)
        return ans;
    int n = words.size();
    int n1 = words[0].size();
    int totalLen = n * n1;
    if (s.size() < totalLen)
        return ans;
    unordered_map<string, int> m1;
    for (auto &word : words)
    {
        m1[word]++;
    }
    for (int i = 0; i <= s.size() - totalLen; i++)
    {
        unordered_map<string, int> m2;
        int j;
        for (j = 0; j < n; j++)
        {
            int startIdx = i + (j * n1);
            string curr = s.substr(startIdx, n1);
            if (m1.find(curr) == m1.end())
            {
                break;
            }
            m2[curr]++;
            if (m2[curr] > m1[curr])
            {
                break;
            }
        }
        if (j == n)
            ans.push_back(i);
    }
    return ans;
}