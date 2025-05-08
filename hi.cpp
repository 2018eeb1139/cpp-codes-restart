#include <iostream>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    int i = 0, j = 0;
    int ans = triangle[0][0];
    while (i < n - 1)
    {
        ans += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        if (triangle[i + 1][j] > triangle[i + 1][j + 1])
        {
            j = j + 1;
        }
        i++;
    }
    return ans;
}
int main()
{
    vector<vector<int>> triangle = {{2},
                                    {3, 4},
                                    {6, 5, 7},
                                    {4, 1, 8, 3}};
    cout << minimumTotal(triangle);
}