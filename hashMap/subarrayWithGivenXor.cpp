int Solution::solve(vector<int> &A, int k)
{
    unordered_map<int, int> m;
    m[0] = 1;
    int ct = 0;
    int xr = 0;
    for (int i = 0; i < A.size(); i++)
    {
        xr = xr ^ A[i];
        if (m.find(k ^ xr) != m.end())
        {
            ct += m[k ^ xr];
        }
        m[xr] += 1;
    }
    return ct;
}
