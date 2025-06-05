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
