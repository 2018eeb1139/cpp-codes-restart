vector<vector<int>> ans;
bool isValid(int rowIdx, int colIdx, int n, vector<vector<int>> &grid)
{
    for (int j = 0; j < colIdx; j++)
    {
        if (grid[rowIdx][j] == 1)
            return false;
    }
    int i = rowIdx, j = colIdx;
    while (i >= 0 && j >= 0)
    {
        if (grid[i][j] == 1)
        {
            return false;
        }
        else
        {
            i--;
            j--;
        }
    }
    i = rowIdx;
    j = colIdx;
    while (i < n && j >= 0)
    {
        if (grid[i][j] == 1)
        {
            return false;
        }
        else
        {
            i++;
            j--;
        }
    }
    return true;
}
void solve(int colIdx, vector<vector<int>> &grid, int n, vector<int> &res)
{
    if (colIdx == n)
    {
        ans.push_back(res);
        return;
    }
    for (int rowIdx = 0; rowIdx < n; rowIdx++)
    {
        if (isValid(rowIdx, colIdx, n, grid))
        {
            grid[rowIdx][colIdx] = 1;
            res.push_back(rowIdx + 1);
            solve(colIdx + 1, grid, n, res);
            res.pop_back();
            grid[rowIdx][colIdx] = 0;
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<int> res;
    solve(0, grid, n, res);
    vector<vector<string>> result;

    for (auto &positions : ans)
    {                                            // Iterate through stored row positions
        vector<string> board(n, string(n, '.')); // Create empty board

        for (int row = 0; row < n; row++)
        {
            board[positions[row] - 1][row] = 'Q'; // Place queen at correct position
        }

        result.push_back(board);
    }

    return result;
}