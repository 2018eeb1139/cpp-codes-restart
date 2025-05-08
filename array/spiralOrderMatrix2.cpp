vector<vector<int>> Solution::generateMatrix(int n)
{

    int left = 0;
    int top = 0;
    int right = n - 1;
    int bottom = n - 1;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int val = 1;
    while (left <= right && top <= bottom)
    {
        for (int j = left; j <= right; j++)
        {
            ans[top][j] = val;
            val++;
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            ans[i][right] = val;
            val++;
        }
        right--;
        for (int j = right; j >= left; j--)
        {
            ans[bottom][j] = val;
            val++;
        }
        bottom--;
        for (int i = bottom; i >= top; i--)
        {
            ans[i][left] = val;
            val++;
        }
        left++;
    }

    return ans;
}
