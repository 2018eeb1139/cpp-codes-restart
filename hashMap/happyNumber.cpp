bool isHappy(int n)
{
    unordered_set<int> s;
    while (1)
    {
        int sum = 0;
        while (n)
        {
            int last = n % 10;
            sum += (last * last);
            n = n / 10;
        }
        if (sum == 1)
            return true;

        n = sum;
        if (s.find(n) != s.end())
            return false;
        s.insert(n);
    }
}