#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int> adj[],vector<bool> &vis,vector<int> &current_cc){
	vis[node]=true;
    current_cc.push_back(node);
	for(int child : adj[node]){
		if(!vis[child]){
			dfs(child,adj,vis,current_cc);
		}
	}
}

int main(){
	int V,E;
	cin>>V>>E;
	vector<int> adj[V+1];
	vector<bool> vis(V+1,false);
    vector<vector<int>> cc;
    vector<int> current_cc;
	for(int i=0;i<E;i++){
		int v1,v2;
		cin>>v1>>v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	int ct=0;
	for(int i=1;i<=V;i++){
		if(!vis[i]){
            current_cc.clear();
			dfs(i,adj,vis,current_cc);
            cc.push_back(current_cc);
			ct++;
		}
	}
	cout<<ct<<endl;
    for(auto curr_cc : cc){
        for(int node : curr_cc){
            cout<<node<<" ";
        }
        cout<<endl;
    }
}