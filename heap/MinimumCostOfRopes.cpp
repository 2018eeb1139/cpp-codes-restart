#include <vector>
#include <queue>
using namespace std;

int minCost(vector<int> &arr)
{
    // code here
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x : arr)
    {
        pq.push(x);
    }
    int cost = 0;
    while (pq.size() >= 2)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        cost += (first + second);
        pq.push(first + second);
    }
    return cost;
}