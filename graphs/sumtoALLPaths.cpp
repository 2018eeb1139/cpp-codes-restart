#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
//         4
//     9       0
// 5       1
void dfs(int node, vector<int> g[], vector<bool> &vis, vector<int> &path, vector<vector<int>> &ans)
{
    vis[node] = true;
    // cout<<node<<endl;
    path.push_back(node);
    if (g[node].size() == 1)
    {
        ans.push_back(path);
    }
    for (int child : g[node])
    {
        if (!vis[child])
        {
            dfs(child, g, vis, path, ans);
        }
    }
    path.pop_back();
}

int main()
{
    int V;
    cin >> V;
    vector<int> g[N];
    vector<bool> vis(N, false);
    for (int i = 0; i < V - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> path;
    vector<vector<int>> ans;
    dfs(1, g, vis, path, ans);
    long long sum = 0;
    for (auto vec : ans)
    {
        string s;
        for (int x : vec)
        {
            cout << x << " ";
            s += char(x + '0');
        }
        sum += stoi(s);
        cout << endl;
    }
    cout << sum;
}
