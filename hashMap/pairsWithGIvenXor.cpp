int Solution::solve(vector<int> &A, int B)
{
    int n = A.size();
    int ct = 0;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.find(A[i] ^ B) != s.end())
        {
            ct++;
        }
        s.insert(A[i]);
    }
    return ct;
}
