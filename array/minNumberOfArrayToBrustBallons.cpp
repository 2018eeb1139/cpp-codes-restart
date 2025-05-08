static bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
int findMinArrowShots(vector<vector<int>> &points)
{
    int n = points.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    sort(points.begin(), points.end(), cmp);
    int ct = 1;
    int end = points[0][1];
    for (int i = 1; i < n; i++)
    {
        if (end >= points[i][0])
        {
            continue;
        }
        else
        {
            ct++;
            end = points[i][1];
        }
    }
    return ct;
}