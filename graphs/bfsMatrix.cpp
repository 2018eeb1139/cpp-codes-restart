#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfsMatrix(vector<vector<int>> &matrix, int startRow, int startCol, vector<vector<bool>> &visited, vector<vector<int>> &level)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    queue<pair<int, int>> q;

    // Directions for moving up, down, left, right
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    q.push({startRow, startCol});
    visited[startRow][startCol] = true;

    while (!q.empty())
    {
        auto [row, col] = q.front();
        q.pop();
        cout << "Visited (" << row << ", " << col << ")\n";

        for (auto [dr, dc] : directions)
        {
            int newRow = row + dr;
            int newCol = col + dc;

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !visited[newRow][newCol])
            {
                q.push({newRow, newCol});
                visited[newRow][newCol] = true;
                level[newRow][newCol] = level[row][col] + 1;
            }
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 1, 0},
        {1, 0, 0, 1}};
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<int>> level(rows, vector<int>(cols, 0));
    int startRow = 0, startCol = 0;
    bfsMatrix(matrix, startRow, startCol, visited, level);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "(" << i << ", " << j << ") " << level[i][j] << endl;
        }
    }
    return 0;
}