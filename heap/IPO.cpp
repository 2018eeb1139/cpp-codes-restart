int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
    // [1,2,3]
    // [0,1,2]
    // k=3
    int n = profits.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({capital[i], profits[i]});
    }
    sort(v.begin(), v.end());
    priority_queue<int> pq;
    int i = 0;
    while (k--)
    {
        while (i < n && v[i].first <= w)
        {
            pq.push(v[i].second);
            i++;
        }
        if (pq.size() == 0)
        {
            break;
        }
        w += pq.top();
        pq.pop();
    }
    return w;
}