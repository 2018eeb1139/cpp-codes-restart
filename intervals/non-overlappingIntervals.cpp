int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    int ct = 0;
    if (n == 1)
        return 0;
    sort(intervals.begin(), intervals.end());
    vector<int> last = intervals[0];
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] < last[1])
        {
            ct++;
            last = intervals[i][1] > last[1] ? last : intervals[i];
        }
        else
        {
            last = intervals[i];
        }
    }
    return ct;
}