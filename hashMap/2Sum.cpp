vector<int> Solution::twoSum(const vector<int> &A, int B)
{
    unordered_map<int, int> m;
    vector<int> v;
    for (int i = 0; i < A.size(); i++)
    {
        if (m.find(B - A[i]) != m.end())
        {
            return {m[B - A[i]], i + 1};
        }
        if (m.find(A[i]) == m.end())
        {
            m[A[i]] = i + 1;
        }
    }
    return v;
}
