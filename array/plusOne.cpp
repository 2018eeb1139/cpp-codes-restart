vector<int> plusOne(vector<int> &digits)
{
    int idx = digits.size() - 1;
    while (idx >= 0)
    {
        if (digits[idx] == 9)
        {
            digits[idx] = 0;
        }
        else
        {
            digits[idx] += 1;
            return digits;
        }
        idx--;
    }
    digits.insert(digits.begin(), 1);
    return digits;
}

vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();
    int carry = 0;
    vector<int> v;
    for (int i = n - 1; i >= 0; i--)
    {
        int sum;
        if (i == n - 1)
        {
            sum = digits[i] + 1;
        }
        else
        {
            sum = (digits[i] + carry);
        }
        carry = (sum / 10);
        int last_dig = (sum % 10);
        v.push_back(last_dig);
    }
    if (carry)
        v.push_back(1);
    reverse(v.begin(), v.end());

    return v;
}