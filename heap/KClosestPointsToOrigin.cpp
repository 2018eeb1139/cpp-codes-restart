#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    priority_queue<pair<int, pair<int, int>>> pq;
    for (auto point : points)
    {
        int dist = (point[0] * point[0] + point[1] * point[1]);
        pq.push({dist, {point[0], point[1]}});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<vector<int>> ans;
    while (pq.size() > 0)
    {
        vector<int> v;
        auto [x, y] = pq.top().second;
        v.push_back(x);
        v.push_back(y);
        ans.push_back(v);
        v.clear();
        pq.pop();
    }
    return ans;
}