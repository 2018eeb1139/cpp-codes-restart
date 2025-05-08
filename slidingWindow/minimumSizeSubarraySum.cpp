int minSubArrayLen(int target, vector<int> &arr)
{
    int n = arr.size();
    int i = 0, j = 0;
    int ans = INT_MAX;
    long long sum = 0;
    while (j < n)
    {
        sum += arr[j];
        if (sum < target)
        {
            j++;
        }
        else if (sum >= target)
        {
            while (sum >= target)
            {
                ans = min(ans, j - i + 1);
                sum -= arr[i];
                i++;
            }
            j++;
        }
    }
    return ans == INT_MAX ? 0 : ans;
}