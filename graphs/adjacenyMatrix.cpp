#include <iostream>
#include <vector>

using namespace std;

void print_graph(vector<vector<int>> &adjMatrix)
{
    int V = adjMatrix.size();
    for (int i = 1; i < V; i++)
    {
        cout << "Node " << i << " " << "child: ";
        for (int j = 1; j < V; j++)
        {
            if (adjMatrix[i][j] == 1)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> edgeList = {
        {1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 3}};
    int V = 5;
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));
    for (int i = 0; i < edgeList.size(); i++)
    {
        int x = edgeList[i][0];
        int y = edgeList[i][1];
        adjMatrix[x][y] = 1;
        adjMatrix[y][x] = 1;
    }
    print_graph(adjMatrix);
}