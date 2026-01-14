int m, n;
vector<pair<int, int>> directions = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(int i, int j, vector<vector<int>> &mat, int &ct)
{
    if (i < 0 || j < 0 || i >= m || j >= n || mat[i][j] == 0)
        return;
    mat[i][j] = 0;
    ct += 1;
    for (auto &dir : directions)
    {
        int newX = i + dir.first;
        int newY = j + dir.second;
        dfs(newX, newY, mat, ct);
    }
}
int maxAreaOfIsland(vector<vector<int>> &mat)
{
    int ans = 0;
    m = mat.size();
    n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 1)
            {
                int ct = 0;
                dfs(i, j, mat, ct);
                ans = max(ans, ct);
            }
        }
    }
    return ans;
}