int Solution::solve(vector<int> &A)
{
    int n = A.size();
    sort(A.begin(), A.end());
    if (A[n - 1] == 0)
        return 1;
    for (int i = 0; i + 1 < n; i++)
    {
        if (A[i] != A[i + 1])
        {
            int ct = 0;
            int p = A[i];
            ct = n - i - 1;
            if (p == ct)
                return 1;
        }
    }
    return -1;
}