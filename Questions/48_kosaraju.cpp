#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj,vector<int>& visited,stack<int>& vert,int node){
    visited[node] = 1;
    for(auto it : adj[node]){
        if(visited[it] == 0)
            dfs(adj,visited,vert,it);
    }
    vert.push(node);
}

void dfs2(vector<vector<int>>& adj,vector<int>& visited,int node){
    visited[node] = 1;
    for(auto it : adj[node]){
        if(visited[it] == 0)
            dfs2(adj,visited,it);
    }
}

int main(){
    vector<vector<int>> adj = {{1},{2},{0,3},{4},{5,7},{6},{4,7},{}};
    stack<int> vert;
    vector<int> visited(adj.size(),0);
    for(int i=0;i<adj.size();i++){
        if(visited[i] == 0)
            dfs(adj,visited,vert,i);
    }
    vector<vector<int>> rev_adj(adj.size());
    for(int i=0;i<adj.size();i++){
        visited[i] = 0;
        for(auto it : adj[i]){
            rev_adj[it].push_back(i);
        }
    }
    int ans = 0;
    while(!vert.empty()){
        int node = vert.top();
        vert.pop();
        if(visited[node] == 1)
            continue;
        dfs2(rev_adj,visited,node);
        ans++;
    }
    cout<<ans<<endl;
}