#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>& adj){
    vector<int> visited(adj.size(),0);
    queue<int> q;
    q.push(0);
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

bool bfs_striver(vector<vector<int>>& adj){
    vector<int> visited(adj.size()+1,0);
    queue<pair<int,int>> q;
    q.push(make_pair(1,-1));
    visited[1] = 1;
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for(int k=0;k<adj[a-1].size();k++){
            if(b!=adj[a-1][k] && visited[adj[a-1][k]] == 1)
                return true;
            if(visited[adj[a-1][k]] == 0){
                q.push(make_pair(adj[a-1][k],a));
                visited[adj[a-1][k]] = 1;
            }
        }
    }
    return false;
}

int main(){
    vector<vector<int>> adj = {{2,3},{1,5},{1,4,6},{3},{2,7},{3,7},{5,6}};
    cout<<boolalpha<<bfs(adj)<<endl;
    cout<<boolalpha<<bfs_striver(adj)<<endl;
}