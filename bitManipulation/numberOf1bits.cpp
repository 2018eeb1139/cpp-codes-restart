int Solution::numSetBits(unsigned int A)
{

    int ct = 0;
    while (A)
    {
        if (A & 1)
        {
            ct++;
        }
        A = A >> 1;
    }
    return ct;
}

int numberOf1Bits(int n)
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
