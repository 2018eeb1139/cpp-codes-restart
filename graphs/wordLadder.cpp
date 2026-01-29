int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{

    unordered_map<string, int> mp;
    unordered_map<string, bool> vis;

    for (string &words : wordList)
    {
        mp[words]++;
        vis[words] = false;
    }
    if (mp.find(endWord) == mp.end())
        return 0;

    queue<string> q;
    q.push(beginWord);
    vis[beginWord] = true;
    int ans = 1;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            auto curr = q.front();
            q.pop();
            for (int i = 0; i < curr.size(); i++)
            {
                char temp = curr[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    curr[i] = c;
                    if (curr == endWord)
                    {
                        return ans + 1;
                    }
                    if (mp.find(curr) != mp.end() && !vis[curr])
                    {
                        vis[curr] = true;
                        q.push(curr);
                    }
                }
                curr[i] = temp;
            }
        }
        ans++;
    }
    return 0;
}