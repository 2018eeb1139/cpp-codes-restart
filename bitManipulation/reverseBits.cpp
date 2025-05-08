uint32_t reverseBits(uint32_t n)
{
    int ans = 0;
    for (int i = 31; i >= 0; i--)
    {
        int last = (n & 1);
        ans = ans << 1;
        ans += last;
        n = n >> 1;
    }
    return ans;
}