#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj,vector<int>& visited,stack<int>& order,int i){
    visited[i] = 1;
    for(int k=0;k<adj[i-1].size();k++){
        if(visited[adj[i-1][k]] == 0){
            dfs(adj,visited,order,adj[i-1][k]);
        }
    }
    order.push(i);
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
    vector<vector<int>> adj = {{},{},{4},{1},{1,2},{1,3}};
    vector<int> visited(adj.size()+1,0);
    stack<int> order;
    print(adj);
    for(int i=0;i<adj.size();i++){
        if(visited[i+1] == 0)
            dfs(adj,visited,order,i+1);
    }
    while(!order.empty()){
        cout<<order.top()<<" ";
        order.pop();
    }
    cout<<endl;
}