vector<pair<int, int>> directions = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int i, int j, int m, int n)
{
    return (i >= 0 && j >= 0 && i < m && j < n);
}

bool dfs(int i, int j, vector<string> &A, string B, int k, int m, int n)
{
    if (k == B.size() - 1)
        return true;
    k++;
    for (auto &dir : directions)
    {
        int newX = i + dir.first;
        int newY = j + dir.second;
        if (isValid(newX, newY, m, n) && A[newX][newY] == B[k])
        {
            if (dfs(newX, newY, A, B, k, m, n) == true)
            {
                return true;
            }
        }
    }
    return false;
}

int Solution::exist(vector<string> &A, string B)
{
    int m = A.size();
    int n = A[0].size();
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (B[k] == A[i][j])
            {
                if (dfs(i, j, A, B, k, m, n))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
