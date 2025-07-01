int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int m = A.size();
    int n = B.size();
    int o = C.size();
    int i = 0, j = 0, k = 0;
    int ans = INT_MAX;
    int mx = INT_MIN;
    int mn = INT_MAX;

    while (i < m && j < n && k < o)
    {
        mx = max({A[i], B[j], C[k]});
        mn = min({A[i], B[j], C[k]});

        ans = min(ans, mx - mn);

        if (mn == A[i])
            i++;
        else if (mn == B[j])
            j++;
        else
            k++;
    }
    return ans;
}
