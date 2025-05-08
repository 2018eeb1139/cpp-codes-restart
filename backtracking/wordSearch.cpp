vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool solve(int idx, int i, int j, string &word, vector<vector<char>> &board, int m, int n)
{
    if (idx == word.size())
    {
        return true;
    }
    if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$')
    {
        return false;
    }
    if (board[i][j] != word[idx])
    {
        return false;
    }
    char ch = board[i][j];
    board[i][j] = '$';
    for (auto &dir : directions)
    {
        int newX = i + dir.first;
        int newY = j + dir.second;
        if (solve(idx + 1, newX, newY, word, board, m, n) == true)
        {
            return true;
        }
    }
    board[i][j] = ch;
    return false;
}
bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == word[0])
            {
                if (solve(0, i, j, word, board, m, n) == true)
                {
                    return true;
                }
            }
        }
    }
    return false;
}