#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj,vector<int>& visited,int i,int j){
    visited[i] = 1;
    for(int k=0;k<adj[i-1].size();k++){
        if(visited[adj[i-1][k]] == 0){
            if(dfs(adj,visited,adj[i-1][k],i))
                return true;
        }
        else{
            if(adj[i-1][k] != j)
                return true;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> adj = {{2},{1,3},{2,4},{3},{6},{5},{8,9},{7},{7}};
    vector<int> visited(adj.size()+1,0);
    bool iscycle = false;
    for(int i=0;i<adj.size();i++){
        if(visited[i+1] == 0)
            if(dfs(adj,visited,i+1,-1))
                iscycle = true;
    }
    cout<<boolalpha<<iscycle<<endl;
}