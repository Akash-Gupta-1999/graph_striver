#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 3,m =3;
    vector<vector<int>> edges = {{0,1,5},{1,2,3},{0,2,1}};
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    vector<vector<int>> MST;
    int min_cost = 0;
    vector<int> visited(n,0);
    pq.push({0,0,0});
    visited[0] = 1;
    while(!pq.empty()){
        vector<int> temp = pq.top();
        pq.pop();
        int node = temp[1];
        int parent = temp[2];
        int cost = temp[0];
        if(!visited[node]){
            min_cost+=cost;
            MST.push_back({parent,node,cost});
            visited[node] = 1;
        }
        for(int k=0;k<adj[node].size();k++){
            int adj_node = adj[node][k].first;
            int w = adj[node][k].second;
            if(!visited[adj_node])
                pq.push({w,adj_node,node});
        }
    }
    for(auto it : MST){
        cout<<it[0]<<"->"<<it[1]<<" : "<<it[2]<<endl;
    }
    cout<<min_cost<<endl;
}