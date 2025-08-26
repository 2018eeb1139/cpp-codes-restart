int Solution::solve(vector<int> &A)
{
    unordered_map<int, int> m;
    for (int &x : A)
    {
        m[x] += 1;
    }
    for (int i = 0; i < A.size(); i++)
    {
        if (m.find(A[i]) != m.end())
        {
            if (m[A[i]] > 1)
            {
                return A[i];
            }
        }
    }
    return -1;
}
