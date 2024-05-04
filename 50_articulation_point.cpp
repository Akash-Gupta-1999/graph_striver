#include<bits/stdc++.h>
using namespace std;

int timer = 0;

void dfs(vector<vector<int>>& adj,vector<int>& visited,vector<int>& tin,vector<int>& min_t,vector<int>& mark,int node,int parent){
    visited[node] = 1;
    tin[node] = min_t[node] = timer;
    timer++;
    int child = 0;
    for(auto it : adj[node]){
        if(it == parent) continue;
        if(visited[it] == 0){
            dfs(adj,visited,tin,min_t,mark,it,node);
            min_t[node] = min(min_t[node],min_t[it]);
            if(min_t[it] >= tin[node] && parent!= -1)
                mark[node] = 1;
            child++;
        }
        else{
            min_t[node] = min(min_t[node],tin[it]);
        }
    }
    if(child>1 && parent == -1)
        mark[node] = 1;
}

int main(){
    int v = 5;
    vector<vector<int>> adj = {{1},{0,4},{3,4},{2,4},{1,2,3}};
    vector<int> visited(v,0),tin(v,0),min_t(v,0),mark(v,0);
    for(int i=0;i<v;i++){
        if(visited[i] == 0){
            dfs(adj,visited,tin,min_t,mark,i,-1);
        }
    }
    vector<int> ans;
    for(int i=0;i<v;i++){
        if(mark[i] == 1)
            ans.push_back(i);
    }
    for(auto it : ans)
        cout<<it<<" ";
    cout<<endl;
}