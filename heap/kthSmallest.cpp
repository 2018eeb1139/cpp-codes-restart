#include <vector>
#include <queue>
using namespace std;

// for arrays
int kthSmallest(vector<int> &v, int k)
{
    priority_queue<int> maxh;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        maxh.push(v[i]);
        if (maxh.size() > k)
        {
            maxh.pop();
        }
    }
    return maxh.top();
}

// for 2d vectors
int kthSmallest(vector<vector<int>> &matrix, int k)
{
    priority_queue<int> maxh;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            maxh.push(matrix[i][j]);
            if (maxh.size() > k)
            {
                maxh.pop();
            }
        }
    }
    return maxh.top();
}