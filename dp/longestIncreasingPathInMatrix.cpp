// 2d variation of Longest Increasing sequence(LIS)

int t[201][201];
int m, n;
bool isValid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < m && j < n);
}
vector<pair<int, int>> directions = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int lis(int i, int j, vector<vector<int>> &a)
{
    if (t[i][j] != -1)
        return t[i][j];
    int ans = 1;
    for (auto &dir : directions)
    {
        int newX = i + dir.first;
        int newY = j + dir.second;
        if (isValid(newX, newY) && a[i][j] < a[newX][newY])
        {
            ans = max(ans, 1 + lis(newX, newY, a));
        }
    }
    return t[i][j] = ans;
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    memset(t, -1, sizeof(t));
    int ans = 1;
    m = matrix.size();
    n = matrix[0].size();
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            ans = max(ans, lis(i, j, matrix));
        }
    }
    return ans;
}