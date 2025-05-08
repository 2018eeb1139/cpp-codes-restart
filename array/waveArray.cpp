vector<int> Solution::wave(vector<int> &A)
{
    int n = A.size();
    if (n == 1)
        return A;
    sort(A.begin(), A.end());
    int i = 0;
    while (i + 1 < n)
    {
        swap(A[i], A[i + 1]);
        i = i + 2;
    }
    return A;
}
