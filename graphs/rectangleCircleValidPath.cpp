vector<pair<int, int>> directions = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}, {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};

bool isValid(int i, int j, int X, int Y)
{
    return (i >= 0 && j >= 0 && i <= X && j <= Y);
}

string Solution::solve(int X, int Y, int N, int R, vector<int> &A, vector<int> &B)
{
    vector<vector<bool>> mat(X + 1, vector<bool>(Y + 1));
    // check every point in rectangle is inside in every circle if yes
    for (int i = 0; i <= X; i++)
    {
        for (int j = 0; j <= Y; j++)
        {
            bool flag = false;
            for (int k = 0; k < A.size(); k++)
            {
                int dist1 = (A[k] - i) * (A[k] - i);
                int dist2 = (B[k] - j) * (B[k] - j);
                if (dist1 + dist2 <= R * R)
                {
                    flag = true;
                    break;
                }
            }
            mat[i][j] = flag;
        }
    }

    if (mat[0][0] == true)
        return "NO";

    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        if (x == X && y == Y)
            return "YES";
        for (auto &dir : directions)
        {
            int newX = x + dir.first;
            int newY = y + dir.second;
            if (isValid(newX, newY, X, Y) && mat[newX][newY] == false)
            {
                q.push({newX, newY});
                mat[newX][newY] = true;
            }
        }
    }
    return "NO";
}
