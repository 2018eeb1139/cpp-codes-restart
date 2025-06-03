vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int i, int j, int n)
{
    return (i >= 0 && i < n && j >= 0 && j < n);
}

int Solution::checkPath(vector<vector<int>> &A)
{
    int n = A.size();
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == 1)
            {
                q.push({i, j});
            }
        }
    }
    int ans = 0;
    bool flag = false;
    while (!q.empty())
    {
        auto curr_node = q.front();
        q.pop();
        int x = curr_node.first;
        int y = curr_node.second;
        for (auto &dir : directions)
        {
            int newX = x + dir.first;
            int newY = y + dir.second;
            if (isValid(newX, newY, n) && A[newX][newY] == 3)
            {
                q.push({newX, newY});
                A[newX][newY] = 0;
            }
            else if (isValid(newX, newY, n) && A[newX][newY] == 2)
            {
                ans = 1;
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    return ans;
}
