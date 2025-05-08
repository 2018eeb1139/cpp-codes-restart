#include <vector>
#include <queue>
using namespace std;

vector<int> frequencySort(vector<int> &nums)
{
    auto cmp = [](pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
            return a.second < b.second; // Sort numbers in descending order
        return a.first > b.first;       // Sort frequency in ascending order
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    vector<int> ans;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        pq.push({it->second, it->first});
    }

    while (pq.size() > 0)
    {
        auto [freq, ele] = pq.top();
        for (int i = 1; i <= freq; i++)
        {
            ans.push_back(ele);
        }
        pq.pop();
    }
    return ans;
}