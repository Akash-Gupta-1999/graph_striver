#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj,vector<int>& visited,vector<int>& path_vis,int i){
    visited[i] = 1;
    path_vis[i] = 1;
    for(int k=0;k<adj[i-1].size();k++){
        if(visited[adj[i-1][k]] == 0){
            if(dfs(adj,visited,path_vis,adj[i-1][k]))
                return true;
        }
        else if(path_vis[adj[i-1][k]] == 1)
            return true;
    }
    path_vis[i] = 0;
    return false;
}

void print(vector<vector<int>>& graph){
    for(int i=0;i<graph.size();i++){
        cout<<i+1<<" : ";
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> adj = {{2,3},{3,4},{6},{1},{6},{},{},{1}};
    vector<int> visited(adj.size()+1,0);
    vector<int> path_vis(adj.size()+1,0);
    print(adj);
    for(int i=0;i<adj.size();i++){
        if(visited[i+1] == 0)
            dfs(adj,visited,path_vis,i+1);
    }
    for(int i=1;i<=adj.size();i++){
        if(path_vis[i] == 0)
            cout<<i<<" ";
    }
    cout<<endl;
}