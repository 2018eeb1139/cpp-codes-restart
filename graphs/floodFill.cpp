#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(int i, int j, int initialColor, int newColor, vector<vector<int>> &image)
{
    int n = image.size();
    int m = image[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m)
        return;
    if (image[i][j] != initialColor)
        return;
    image[i][j] = newColor;

    for (auto &dir : directions)
    {
        int newX = i + dir.first;
        int newY = j + dir.second;
        dfs(newX, newY, initialColor, newColor, image);
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int initialColor = image[sr][sc];
    if (initialColor != newColor)
    {
        dfs(sr, sc, initialColor, newColor, image);
    }
    return image;
}