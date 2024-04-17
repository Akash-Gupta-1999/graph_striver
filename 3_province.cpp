#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>& graph){
    for(int i=1;i<graph.size();i++){
        cout<<i<<" : ";
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

void dfs(vector<vector<int>>& graph,vector<int>& visited,int n,int k){
    visited[k] = 1;
    for(int i=0;i<graph[k].size();i++){
        if(visited[graph[k][i]] == 0)
            dfs(graph,visited,n,graph[k][i]);
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    print(graph);
    vector<int> visited(n+1,0);
    int prov = 0;
    for(int i=1;i<n+1;i++){
        if(visited[i] == 0){
            prov++;
            dfs(graph,visited,n,i);
        }
    }
    cout<<prov<<endl;
}