double myPow(double a, int b)
{
    double ans = 1.0;
    long long bb = b;
    if (bb > 0)
    {
        while (bb)
        {
            if (bb & 1)
            {
                ans = ans * a;
            }
            a = a * a;
            bb = bb >> 1;
        }
    }
    else
    {
        bb = abs(bb);
        while (bb)
        {
            if (bb & 1)
            {
                ans = ans * a;
            }
            a = a * a;
            bb = bb >> 1;
        }
        ans = 1.0 / ans;
    }
    return ans;
}