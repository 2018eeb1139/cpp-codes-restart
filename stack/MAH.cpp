#include <iostream>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<pair<int, int>> s;
    vector<int> left;
    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
            left.push_back(-1);
        else if (s.size() > 0 && s.top().first < heights[i])
            left.push_back(s.top().second);
        else if (s.size() > 0 && s.top().first >= heights[i])
        {
            while (s.size() > 0 && s.top().first >= heights[i])
                s.pop();

            if (s.size() == 0)
                left.push_back(-1);
            else
                left.push_back(s.top().second);
        }
        s.push({heights[i], i});
    }
    while (!s.empty())
        s.pop();

    vector<int> right;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s.size() == 0)
            right.push_back(n);
        else if (s.size() > 0 && s.top().first < heights[i])
            right.push_back(s.top().second);
        else if (s.size() > 0 && s.top().first >= heights[i])
        {
            while (s.size() > 0 && s.top().first >= heights[i])
                s.pop();

            if (s.size() == 0)
                right.push_back(n);
            else
                right.push_back(s.top().second);
        }
        s.push({heights[i], i});
    }

    reverse(right.begin(), right.end());

    vector<int> width(n);
    for (int i = 0; i < n; i++)
    {
        width[i] = right[i] - left[i] - 1;
    }
    vector<int> area(n);
    for (int i = 0; i < n; i++)
    {
        area[i] = width[i] * heights[i];
    }
    return *max_element(area.begin(), area.end());
}