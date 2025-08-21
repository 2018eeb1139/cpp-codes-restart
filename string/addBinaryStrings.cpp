string Solution::addBinary(string A, string B)
{
    int carry = 0;

    int i = A.size() - 1;
    int j = B.size() - 1;

    string ans = "";
    while (i >= 0 || j >= 0)
    {
        int sum = carry;
        if (i >= 0)
        {
            sum += A[i] - '0';
            i--;
        }
        if (j >= 0)
        {
            sum += B[j] - '0';
            j--;
        }

        ans.push_back(char((sum % 2) + '0'));
        carry = sum / 2;
    }

    if (carry)
        ans.push_back('1');

    reverse(ans.begin(), ans.end());
    return ans;
}
