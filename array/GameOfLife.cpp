vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};
bool isValid(int i, int j, int m, int n)
{
    if (i >= 0 && j >= 0 && i < m && j < n)
    {
        return true;
    }
    return false;
}
void checkNeighbor(int i, int j, vector<vector<int>> &board, vector<vector<int>> &v, int m, int n)
{
    int live = 0;
    int die = 0;
    for (auto &p : directions)
    {
        int newX = i + p.first;
        int newY = j + p.second;
        if (isValid(newX, newY, m, n))
        {
            if (board[newX][newY] == 1)
            {
                live += 1;
            }
            else
            {
                die += 1;
            }
        }
    }
    if (board[i][j] == 1)
    {
        if (live < 2)
        {
            v[i][j] = 0;
        }
        else if (live == 2 || live == 3)
        {
            v[i][j] = 1;
        }
        else if (live > 3)
        {
            v[i][j] = 0;
        }
    }
    else if (board[i][j] == 0)
    {
        if (live == 3)
        {
            v[i][j] = 1;
        }
    }
}
void gameOfLife(vector<vector<int>> &board)
{
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> v(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            checkNeighbor(i, j, board, v, m, n);
        }
    }
    board = v;
}