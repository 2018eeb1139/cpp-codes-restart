string Solution::convert(string s, int m)
{
    if (m == 1)
        return s;
    int n = s.size();
    vector<vector<char>> mat(m, vector<char>(n, '#'));
    int i = 0;
    int j = 0;
    char D = 'D';
    while (j < n)
    {
        while (i < m && j < n && D == 'D')
        {
            mat[i][j] = s[j];
            i++;
            j++;
        }
        if (i >= m)
        {
            i = i - 2;
            D = 'U';
        }
        while (i >= 0 && j < n && D == 'U')
        {
            mat[i][j] = s[j];
            i--;
            j++;
        }
        if (i < 0)
        {
            i = i + 2;
            D = 'D';
        }
    }
    string ans = "";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != '#')
            {
                ans += mat[i][j];
            }
        }
    }
    return ans;
}
