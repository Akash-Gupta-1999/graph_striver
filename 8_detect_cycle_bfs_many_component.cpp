#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>& adj,vector<int>& visited,int a){
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        int n = q.front();
        q.pop();
        if(visited[n] == 0){
            visited[n] = 1;
            for(int k=0;k<adj[n].size();k++){
                if(visited[adj[n][k]-1] == 0){
                    q.push(adj[n][k]-1);
                }
            }
        }
        else
            return true;
    }
    return false;
}

int main(){
    vector<vector<int>> adj = {{2},{3,1},{2,4},{3},{6},{5},{8,9},{7,9},{7,8}};
    vector<int> visited(adj.size(),0);
    bool iscycle = false;
    for(int i=0;i<adj.size();i++){
        if(visited[i+1] == 0)
            if(bfs(adj,visited,i+1))
                iscycle = true;
    }
    cout<<boolalpha<<iscycle<<endl;
}