#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<pair<int,int>>>& adj,vector<int>& visited,stack<int>& order,int node){
    visited[node] = 1;
    for(auto it : adj[node]){
        if(visited[it.first] == 0)
            dfs(adj,visited,order,it.first);
    }
    order.push(node);
}

int main(){
    int n = 6, m = 7;
    vector<vector<int>> edge = {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        int u = edge[i][0];
        int v = edge[i][1];
        int w = edge[i][2];
        adj[u].push_back({v,w});
    }
    vector<int> visited(n,0);
    stack<int> order;
    for(int i=0;i<n;i++){
        if(visited[i] == 0){
            dfs(adj,visited,order,i);
        }
    }
    vector<int> dist(n,1e9);
    dist[0] = 0;
    while(!order.empty()){
        int node = order.top();
        order.pop();
        for(auto it : adj[node]){
            int v = it.first;
            int w = it.second;
            if(dist[node]+w<dist[v])
                dist[v] = dist[node] + w;
        }
    }
    for(auto it : dist){
        cout<<it<<" ";
    }
    cout<<endl;
}