int Solution::solve(string s)
{
    int n = s.size();
    if (n == 1)
        return 1;

    bool evenCount = false;
    bool oddCount = false;

    unordered_map<char, int> m;
    for (char &c : s)
    {
        m[c] += 1;
    }

    for (auto &x : m)
    {
        if (x.second % 2 == 0)
            continue;
        else if ((x.second & 1) && oddCount == false)
        {
            oddCount = true;
        }
        else if (oddCount == true)
        {
            return 0;
        }
    }
    return 1;
}
