#include <iostream>
#include <vector>

using namespace std;

int hist(vector<int> &v)
{
    int n = v.size();
    vector<int> left(n);
    left[0] = -1;
    stack<pair<int, int>> st;
    st.push({v[0], 0});

    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && st.top().first >= v[i])
            st.pop();
        if (st.empty())
            left[i] = -1;
        else
            left[i] = st.top().second;
        st.push({v[i], i});
    }

    vector<int> right(n);
    right[n - 1] = n;
    while (!st.empty())
        st.pop();
    st.push({v[n - 1], n - 1});

    for (int i = n - 2; i >= 0; i--)
    {
        while (!st.empty() && st.top().first >= v[i])
            st.pop();
        if (st.empty())
            right[i] = n;
        else
            right[i] = st.top().second;
        st.push({v[i], i});
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int area = v[i] * (right[i] - left[i] - 1);
        ans = max(ans, area);
    }
    return ans;
}

int maximalRectangle(vector<vector<char>> &v)
{
    int m = v.size();
    if (m == 0)
        return 0;
    int n = v[0].size();

    vector<vector<int>> grid(m, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        if (v[0][i] == '1')
            grid[0][i] = 1;

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == '1')
                grid[i][j] = 1 + grid[i - 1][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
        ans = max(ans, hist(grid[i]));
    return ans;
}