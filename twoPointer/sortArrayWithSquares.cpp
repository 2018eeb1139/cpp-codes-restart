vector<int> Solution::solve(vector<int> &A)
{
    int n = A.size();
    vector<int> v(n);
    int i = 0;
    int j = n - 1;
    int k = n - 1;
    while (i <= j)
    {
        if (abs(A[i]) > abs(A[j]))
        {
            v[k--] = A[i] * A[i];
            i++;
        }
        else
        {
            v[k--] = A[j] * A[j];
            j--;
        }
    }
    return v;
}