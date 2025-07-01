vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B)
{
    int m = A.size();
    int n = B.size();
    vector<int> v;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (A[i] == B[j])
        {
            v.push_back(A[i]);
            i++;
            j++;
        }
        else if (A[i] < B[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return v;
}
