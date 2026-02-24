string reorganizeString(string s)
{
    int n = s.size();
    if (n == 1)
        return s;
    vector<int> hsh(26, 0);
    for (int i = 0; i < n; i++)
    {
        hsh[s[i] - 'a']++;
        if (hsh[s[i] - 'a'] > (n + 1) / 2)
            return "";
    }
    priority_queue<pair<int, char>> pq;
    for (int i = 0; i < 26; i++)
    {
        if (hsh[i] > 0)
        {
            pq.push({hsh[i], i + 'a'});
        }
    }
    string res = "";
    while (pq.size() >= 2)
    {
        auto p1 = pq.top();
        pq.pop();
        auto p2 = pq.top();
        pq.pop();
        res.push_back(p1.second);
        p1.first--;
        res.push_back(p2.second);
        p2.first--;
        if (p1.first > 0)
        {
            pq.push(p1);
        }
        if (p2.first > 0)
        {
            pq.push(p2);
        }
    }
    if (!pq.empty())
    {
        res.push_back(pq.top().second);
    }
    return res;
}