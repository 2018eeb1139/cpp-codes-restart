int Solution::divisibleBy60(vector<int> &v)
{

    int sum = 0;
    int zeroCount = 0;
    int evenCount = 0;

    for (int digit : v)
    {
        sum += digit;
        if (digit == 0)
            zeroCount++;
        if (digit % 2 == 0)
            evenCount++;
    }

    if (zeroCount == 0)
        return 0;
    if (sum % 3 != 0)
        return 0;
    if (v.size() > 1 && evenCount < 2)
        return 0;

    return 1;
}
