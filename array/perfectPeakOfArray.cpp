int Solution::perfectPeak(vector<int> &A)
{
    int N = A.size();
    if (N < 3)
        return 0;
    [5 1 4 3 6 8 10 7 9]
        [5 1 1 1 1 1 1 1 1]
        [1 1 3 3 6 7 7 7 9] vector<int>
            prefixMax(N);
    vector<int> suffixMin(N);

    prefixMax[0] = A[0];
    for (int i = 1; i < N; i++)
        prefixMax[i] = max(prefixMax[i - 1], A[i]);

    suffixMin[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; i--)
        suffixMin[i] = min(suffixMin[i + 1], A[i]);

    for (int i = 1; i < N - 1; i++)
    {
        if (A[i] > prefixMax[i - 1] && A[i] < suffixMin[i + 1])
            return 1;
    }

    return 0;
}
