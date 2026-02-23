string frequencySort(string s)
{
    string res = "";
    unordered_map<char, int> m;
    priority_queue<pair<int, int>> pq;
    for (char &c : s)
        m[c] += 1;

    for (auto &x : m)
    {
        pq.push({x.second, x.first});
    }
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int ct = top.first;
        char c = top.second;
        while (ct--)
        {
            res += c;
        }
    }
    return res;
}