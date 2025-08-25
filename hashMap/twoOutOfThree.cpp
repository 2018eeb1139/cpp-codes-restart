vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C)
{
    unordered_map<int, int> m1;
    unordered_set<int> s1, s2, s3;
    for (int &num : A)
    {
        s1.insert(num);
    }
    for (int &num : B)
    {
        s2.insert(num);
    }
    for (int &num : C)
    {
        s3.insert(num);
    }
    for (auto &x : s1)
    {
        m1[x] += 1;
    }
    for (auto &x : s2)
    {
        m1[x] += 1;
    }
    for (auto &x : s3)
    {
        m1[x] += 1;
    }
    vector<int> v;
    for (auto &x : m1)
    {
        if (x.second >= 2)
        {
            v.push_back(x.first);
        }
    }
    sort(v.begin(), v.end());
    return v;
}
