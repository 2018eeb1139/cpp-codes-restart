#include <bits/stdc++.h>
using namespace std;

void dfs(int node,int par,vector<int> adj[], vector<int> &depth,vector<int> &height,vector<int> &subtree_sum,vector<int> &even_ct){
    subtree_sum[node] += node;
    if(node % 2 == 0) even_ct[node]++;
    for(int child : adj[node]){
        if(child != par){
            depth[child] = depth[node]+1;
            dfs(child,node,adj,depth,height,subtree_sum,even_ct);
            height[node] = max(height[node],height[child]+1);
            subtree_sum[node] += subtree_sum[child];
            even_ct[node] += even_ct[child];
        }
    }
}

int main() {
    int V;
    cin>>V;
    vector<int> adj[V+1];
    // tree will have V-1 edges
    for(int i=1;i<=V-1;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int> depth(V+1,0);
    vector<int> height(V+1,0);
    vector<int> subtree_sum(V+1,0);
    vector<int> even_ct(V+1,0);

    dfs(1,-1,adj,depth,height,subtree_sum,even_ct);

    cout << "Node\tDepth\tHeight\tSubtreeSum\tEvenCount" << endl;
    for (int i = 1; i <= V; i++) {
        cout << i << "\t" << depth[i] << "\t" << height[i] << "\t" << subtree_sum[i]<< "\t\t"<<even_ct[i]<< endl;
    }
    
}
