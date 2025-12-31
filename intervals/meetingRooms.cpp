// leetcode

static bool cmp(const Interval &a, const Interval &b)
{
    if (a.start < b.start)
        return true;
    if (a.start == b.start)
        return a.end < b.end;
    return false;
}
bool canAttendMeetings(vector<Interval> &intervals)
{
    int n = intervals.size();
    if (n == 0 || n == 1)
        return true;
    sort(intervals.begin(), intervals.end(), cmp);
    Interval last = intervals[0];
    for (int i = 1; i < n; i++)
    {
        if (intervals[i].start < last.end)
        {
            return false;
        }
        last = intervals[i];
    }
    return true;
}

// GFG
bool canAttend(vector<vector<int>> &intervals)
{
    // Code Here
    int n = intervals.size();
    if (n == 1)
        return true;
    sort(intervals.begin(), intervals.end());
    vector<int> last = intervals[0];
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] < last[1])
        {
            return false;
        }
        else
        {
            last = intervals[i];
        }
    }
    return true;
}