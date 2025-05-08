int rangeBitwiseAnd(int left, int right)
{
    if (left == 0 || right == 0)
        return 0;
    if (left == right)
        return left;
    int i = 0;
    while (left != right)
    {
        left = left >> 1;
        right = right >> 1;
        i++;
    }
    return left << i;
}