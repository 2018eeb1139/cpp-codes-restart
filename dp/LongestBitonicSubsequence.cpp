int dp1[1001], dp2[1001];

int LIS(int i, const vector<int> &a)
{
    if (dp1[i] != -1)
        return dp1[i];
    int ans = 1;
    for (int j = 0; j < i; j++)
    {
        if (a[j] < a[i])
        {
            ans = max(ans, LIS(j, a) + 1);
        }
    }
    return dp1[i] = ans;
}

int LDS(int i, const vector<int> &a)
{
    if (dp2[i] != -1)
        return dp2[i];
    int ans = 1;
    for (int j = i + 1; j < (int)a.size(); j++)
    {
        if (a[j] < a[i])
        {
            ans = max(ans, LDS(j, a) + 1);
        }
    }
    return dp2[i] = ans;
}

int Solution::longestBitonicSubsequenceLength(const vector<int> &a)
{
    int n = a.size();
    if (n == 0)
        return 0;
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));

    // if(n == 0) return 0;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int inc = LIS(i, a);
        int dec = LDS(i, a);
        ans = max(ans, inc + dec - 1);
    }
    return ans;
}
