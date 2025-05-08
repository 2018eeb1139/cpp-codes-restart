#include <iostream>
#include <vector>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);
    vector<int> ans;
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int x = prerequisites[i][1];
        int y = prerequisites[i][0];
        adj[x].push_back(y);
        indegree[y]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int curr_node = q.front();
        ans.push_back(curr_node);
        q.pop();
        for (int &child : adj[curr_node])
        {
            indegree[child]--;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }
    for (int i = 0; i < numCourses; i++)
    {
        if (indegree[i] != 0)
            return {};
    }
    return ans;
}