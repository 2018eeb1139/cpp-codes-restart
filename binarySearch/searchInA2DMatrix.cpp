#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int m = mat.size();
    int n = mat[0].size();
    int i = 0;
    int j = n - 1;
    while (i >= 0 && i < m && j >= 0 && j < n)
    {
        if (mat[i][j] == target)
        {
            return true;
        }
        else if (target > mat[i][j])
        {
            i++;
        }
        else if (target < mat[i][j])
        {
            j--;
        }
    }
    return false;
}

pair<int, int> searchMatrix2(vector<vector<int>> &mat, int target)
{
    int m = mat.size();
    int n = mat[0].size();
    int i = 0;
    int j = n - 1;
    while (i >= 0 && i < m && j >= 0 && j < n)
    {
        if (mat[i][j] == target)
        {
            return {i, j};
        }
        else if (target > mat[i][j])
        {
            i++;
        }
        else if (target < mat[i][j])
        {
            j--;
        }
    }
    return {-1, -1};
}