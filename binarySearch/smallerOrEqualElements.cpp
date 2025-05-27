int Solution::solve(vector<int> &a, int target)
{
    int idx;
    int n = a.size();
    if (a[n - 1] <= target)
        return n;
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == target)
        {
            start = mid + 1;
        }
        else if (a[mid] < target)
        {
            start = mid + 1;
        }
        else if (a[mid] > target)
        {
            idx = mid;
            end = mid - 1;
        }
    }
    return idx;
}
