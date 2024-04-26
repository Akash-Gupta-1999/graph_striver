#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 7,m = 10;
    vector<vector<int>> edges = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(n,1e9),ways(n,0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push(make_pair(dist[0],0));
    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        for(int k=0;k<adj[u].size();k++){
            int v = adj[u][k].first;
            int w = adj[u][k].second;
            if(d + w < dist[v]){
                dist[v] = d+w;
                pq.push(make_pair(dist[v],v));
                ways[v] = ways[u];
            }
            else if(d + w == dist[v]){
                ways[v] = ways[v] + ways[u];
            }
        }
    }
    cout<<ways[n-1]<<endl;
}