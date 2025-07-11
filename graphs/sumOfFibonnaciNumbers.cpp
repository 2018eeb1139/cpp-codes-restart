int Solution::fibsum(int n)
{
    vector<int> fib = {1, 1};

    // Generate Fibonacci numbers ≤ n
    while (fib.back() <= n)
    {
        int sz = fib.size();
        int next = fib[sz - 1] + fib[sz - 2];
        if (next > n)
            break;
        fib.push_back(next);
    }

    int ct = 0;
    int i = fib.size() - 1;

    // Greedily subtract the largest Fibonacci number ≤ n
    while (n > 0)
    {
        if (fib[i] <= n)
        {
            n -= fib[i];
            ct++;
        }
        else
        {
            i--;
        }
    }

    return ct;
}
