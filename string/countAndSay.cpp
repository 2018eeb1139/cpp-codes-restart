string Solution::countAndSay(int n)
{
    if (n == 1)
        return "1";
    string ans = "";
    string s = countAndSay(n - 1);
    int sz = s.size();
    for (int i = 0; i < sz; i++)
    {
        char ch = s[i];
        int ct = 1;
        while (i + 1 < sz && s[i] == s[i + 1])
        {
            i++;
            ct++;
        }
        ans += to_string(ct) + string(1, ch);
    }

    return ans;
}
