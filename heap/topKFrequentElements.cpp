#include <vector>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> ans;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        pq.push({it->second, it->first});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    while (pq.size() > 0)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}