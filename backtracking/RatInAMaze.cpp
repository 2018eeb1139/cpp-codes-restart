#include <vector>
#include <string>
using namespace std;

class Direction
{
public:
    int dx;
    int dy;
    char dir;
};
vector<Direction> directions = {
    {-1, 0, 'U'}, {1, 0, 'D'}, {0, -1, 'L'}, {0, 1, 'R'}};
bool isValid(int i, int j, int n, vector<vector<int>> &maze)
{
    return (i >= 0 && j >= 0 && i < n && j < n && maze[i][j] == 1);
}
void solve(int i, int j, int n, string &path, vector<string> &res, vector<vector<int>> &maze)
{
    if (i == n - 1 && j == n - 1)
    {
        res.push_back(path);
        return;
    }
    for (auto &direction : directions)
    {
        int newX = i + direction.dx;
        int newY = j + direction.dy;
        if (isValid(newX, newY, n, maze))
        {
            path.push_back(direction.dir);
            maze[i][j] = 0;
            solve(newX, newY, n, path, res, maze);
            maze[i][j] = 1;
            path.pop_back();
        }
    }
}
vector<string> ratInMaze(vector<vector<int>> &maze)
{
    // code here
    int n = maze.size();
    vector<string> res;
    if (maze[0][0] == 1)
    {
        string path = "";
        solve(0, 0, n, path, res, maze);
    }
    sort(res.begin(), res.end());
    return res;
}