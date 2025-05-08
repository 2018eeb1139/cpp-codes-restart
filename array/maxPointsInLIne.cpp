int maxPoints(vector<vector<int>> &points)
{
    int n = points.size();
    if (n == 1)
        return 1;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        unordered_map<double, int> m;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            else
            {
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                double angle = atan2(dy, dx);
                m[angle] += 1;
            }
        }
        for (auto x : m)
        {
            ans = max(ans, x.second);
        }
    }
    return ans + 1;
}