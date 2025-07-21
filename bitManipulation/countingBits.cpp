int countSetBits(int n)
{
    int ct = 0;
    for (int i = 31; i >= 0; i--)
    {
        if ((n & (1 << i)) != 0)
        {
            ct++;
        }
    }
    return ct;
}
vector<int> countBits(int n)
{
    vector<int> v(n + 1);
    for (int i = 0; i <= n; i++)
    {
        v[i] = countSetBits(i);
    }
    return v;
}