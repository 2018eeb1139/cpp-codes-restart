#include <iostream>
#include <vector>

using namespace std;

void print_graph(vector<int> adj[], int V)
{
    for (int i = 1; i <= V; i++)
    {
        cout << "Node " << i << " child: ";
        for (int child : adj[i])
        {
            cout << child << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> edgeList = {
        {1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 3}};
    int V = 4;
    vector<int> adj[V + 1]; // Array of vectors

    for (const auto &edge : edgeList)
    {
        int x = edge[0], y = edge[1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    print_graph(adj, V);
}
