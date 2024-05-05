#include<bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(vector<vector<int>>& adj,vector<int>& visited,vector<int>& tin,vector<int>& min_t,vector<vector<int>>& bridges,int node,int parent){
    visited[node] = 1;
    tin[node] = min_t[node] = timer;
    timer++;
    for(auto it : adj[node]){
        if(visited[it] == 0){
            dfs(adj,visited,tin,min_t,bridges,it,node);
            min_t[node] = min(min_t[node],min_t[it]);
            if(min_t[it] > tin[node]){
                bridges.push_back({node,it});
            }
        }
        else{
            if(it!=parent)
                min_t[node] = min(min_t[node],min_t[it]);
        }
    }
}

int main(){
    int n = 4;
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> adj(n);
    for(auto it : connections){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> tin(n,0),min_t(n,0),visited(n,0);
    vector<vector<int>> bridges;
    dfs(adj,visited,tin,min_t,bridges,0,-1);
    for(auto it : bridges)
        cout<<it[0]<<"->"<<it[1]<<endl;
}