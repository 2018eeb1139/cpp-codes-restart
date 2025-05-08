#include <vector>
#include <string>
using namespace std;

vector<vector<int>> ans;
bool isValid(int rowIdx, int colIdx, int n, vector<vector<int>> &grid)
{
    // check left row
    for (int j = 0; j < colIdx; j++)
    {
        if (grid[rowIdx][j] == 1)
            return false;
    }
    int i = rowIdx, j = colIdx;
    // check upper diagonal
    while (i >= 0 && j >= 0)
    {
        if (grid[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }
    i = rowIdx;
    j = colIdx;
    // check lower diagonal
    while (i < n && j >= 0)
    {
        if (grid[i][j] == 1)
        {
            return false;
        }
        i++;
        j--;
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
    // col wise traversal
    for (int rowIdx = 0; rowIdx < n; rowIdx++)
    {
        if (isValid(rowIdx, colIdx, n, grid))
        {
            grid[rowIdx][colIdx] = 1; // mark it visited
            res.push_back(rowIdx + 1);
            solve(colIdx + 1, grid, n, res);
            res.pop_back(); // bactracking
            grid[rowIdx][colIdx] = 0;
        }
    }
}
vector<vector<int>> nQueen(int n)
{
    // code here
    vector<vector<int>> grid(n, vector<int>(n, 0));
    vector<int> res;
    solve(0, grid, n, res);
    return ans;
}