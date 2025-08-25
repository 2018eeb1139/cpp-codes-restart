int Solution::colorful(int A)
{
    vector<int> v;
    while (A > 0)
    {
        int rem = (A % 10);
        v.push_back(rem);
        A = A / 10;
    }
    set<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        int prod = 1;
        for (int j = i; j < v.size(); j++)
        {
            prod = prod * v[j];
            if (s.find(prod) != s.end())
            {
                return 0;
            }
            else
            {
                s.insert(prod);
            }
        }
    }
    return 1;
}
