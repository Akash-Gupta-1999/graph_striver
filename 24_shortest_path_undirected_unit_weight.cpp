#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 9,m = 10;
    vector<vector<int>> edges = {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    queue<int> q;
    q.push(0);
    vector<int> dist(n,1e9);
    dist[0] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto it : adj[u]){
            if(dist[u] + 1 < dist[it]){
                dist[it] = dist[u] + 1;
                q.push(it);
            }
        }
    }
    for(auto it : dist)
        cout<<it<<" ";
    cout<<endl;
}