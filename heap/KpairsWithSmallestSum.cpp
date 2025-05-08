#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> ans;
    for (int i = 0; i < min(k, (int)nums2.size()); i++)
    {
        int sum = nums1[0] + nums2[i];
        pq.push({sum, {0, i}});
    }
    while (!pq.empty() && k--)
    {
        auto res = pq.top();
        int i = res.second.first;
        int j = res.second.second;
        pq.pop();
        ans.push_back({nums1[i], nums2[j]});
        if (i + 1 < nums1.size())
        {
            int sum = nums1[i + 1] + nums2[j];
            pq.push({sum, {i + 1, j}});
        }
    }
    return ans;
}