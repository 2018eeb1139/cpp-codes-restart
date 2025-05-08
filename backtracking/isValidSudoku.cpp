bool isValidSudoku(vector<vector<char>> &board)
{
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '.')
                continue;
            else
            {
                char ch = board[i][j];
                for (int k = 0; k < n; k++)
                {
                    if (k == j)
                        continue;
                    if (board[i][k] == ch)
                    {
                        return false;
                    }
                }
                for (int t = 0; t < m; t++)
                {
                    if (t == i)
                        continue;
                    if (board[t][j] == ch)
                    {
                        return false;
                    }
                }
                int ii = (i / 3) * 3;
                int jj = (j / 3) * 3;
                for (int s = ii; s < ii + 3; s++)
                {
                    for (int u = jj; u < jj + 3; u++)
                    {
                        if (s == i && u == j)
                            continue;
                        if (board[s][u] == ch)
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}