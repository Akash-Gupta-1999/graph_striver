#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 4,m = 4;
    int thresh = 4;
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    vector<vector<int>> dist(n,vector<int>(n,1e9));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i=0;i<n;i++){
        dist[i][i] = 0;
        pq.push(make_pair(dist[i][i],i));
        while(!pq.empty()){
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            for(int k=0;k<adj[u].size();k++){
                int v = adj[u][k].first;
                int w = adj[u][k].second;
                if(d+w<dist[i][v]){
                    dist[i][v] = d+w;
                    pq.push(make_pair(dist[i][v],v));
                }
            }
        }
    }
    int ans_min = INT_MAX;
    int ans_node = -1;
    for(int i = n-1;i>=0;i--){
        int c = 0;
        for(auto it : dist[i]){
            if(it <= thresh){
                c++;
            }
        }
        if(c<ans_min){
            ans_node = i;
            ans_min = c;
        }
    }
    cout<<ans_node<<" "<<ans_min<<endl;
}