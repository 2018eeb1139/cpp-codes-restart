int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }
    return triangle[0][0];
}

// interviewBit
int Solution::minimumTotal(vector<vector<int>> &A)
{
    int m = A.size();
    if (m == 1)
        return A[0][0];

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            A[i][j] += min(A[i + 1][j], A[i + 1][j + 1]);
        }
    }
    return A[0][0];
}