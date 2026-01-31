int n;
int t[100][100];
bool solve(int i, int open, string s)
{
    if (i == n)
    {
        if (open == 0)
            return true;
        else
            return false;
    }
    if (t[i][open] != -1)
        return t[i][open];
    bool ans = false;
    if (s[i] == '(')
    {
        ans = solve(i + 1, open + 1, s);
    }
    else if (s[i] == '*')
    {
        ans |= solve(i + 1, open + 1, s);
        ans |= solve(i + 1, open, s);
        if (open > 0)
        {
            ans |= solve(i + 1, open - 1, s);
        }
    }
    else if (open > 0)
    {
        ans |= solve(i + 1, open - 1, s);
    }
    return t[i][open] = ans;
}

bool checkValidString(string s)
{
    memset(t, -1, sizeof(t));
    int open = 0;
    n = s.size();
    return solve(0, open, s);
}