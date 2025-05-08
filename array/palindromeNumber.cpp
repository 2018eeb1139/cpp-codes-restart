bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    string res = "";
    while (x > 0)
    {
        int last_digit = x % 10;
        res.push_back(char(last_digit + '0'));
        x = x / 10;
    }
    reverse(res.begin(), res.end());
    int i = 0, j = res.size() - 1;
    bool flag = true;
    while (i < j)
    {
        if (res[i] != res[j])
        {
            flag = false;
            break;
        }
        else
        {
            i++;
            j--;
        }
    }
    if (flag)
        return true;
    else
        return false;
}