string multiply(string num1, string num2)
{
    if (num1 == "0" || num2 == "0")
        return "0";

    int m = num1.size();
    int n = num2.size();

    vector<int> res(m + n, 0);

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int digit = (num1[i] - '0') * (num2[j] - '0');
            res[i + j] += digit;
        }
    }

    for (int i = 0; i < m + n; i++)
    {
        int carry = res[i] / 10;
        res[i] %= 10;
        if (i + 1 < m + n)
            res[i + 1] += carry;
    }

    int i = m + n - 1;
    while (i > 0 && res[i] == 0)
        i--;

    string ans = "";
    while (i >= 0)
    {
        ans += (res[i] + '0');
        i--;
    }

    return ans;
}