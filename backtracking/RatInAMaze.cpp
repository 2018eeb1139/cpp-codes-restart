#include <vector>
#include <string>
using namespace std;

struct Choice
{
    char dname;
    int dx;
    int dy;
};
bool isSolved(int x, int y, int n)
{
    return (x == n - 1 && y == n - 1);
}
bool isValid(int x, int y, int n, vector<vector<int>> &arr)
{
    return (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 1);
}
void solve(int x, int y, int n, vector<string> &res, string &path, vector<vector<int>> &arr, vector<Choice> &choices)
{
    if (isSolved(x, y, n))
    {
        res.push_back(path);
        return;
    }
    for (auto &choice : choices)
    {
        int newX = x + choice.dx;
        int newY = y + choice.dy;
        if (isValid(newX, newY, n, arr))
        {
            arr[newX][newY] = 0; // mark it visited
            path.push_back(choice.dname);
            solve(newX, newY, n, res, path, arr, choices);
            arr[newX][newY] = 1; // bactracking;
            path.pop_back();     // backtracking
        }
    }
}
vector<string> findPath(vector<vector<int>> &arr)
{
    // code here
    int n = arr.size();
    vector<string> res;
    if (n == 0 || arr[0][0] == 0)
        return res; // Edge case handling
    string path = "";
    vector<Choice> choices = {
        {'U', -1, 0},
        {'D', 1, 0},
        {'L', 0, -1},
        {'R', 0, 1}};
    arr[0][0] = 0; // Mark the starting point as visited
    solve(0, 0, n, res, path, arr, choices);
    return res;
}