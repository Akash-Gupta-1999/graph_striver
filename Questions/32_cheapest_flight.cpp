#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 4;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src = 0,dst = 3,k = 1;
    vector<vector<pair<int,int>>> adj(n);
    for(auto it : flights){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        adj[u].push_back(make_pair(v,w));
    }
    queue<vector<int>> q;
    vector<int> dist(n,1e9);
    q.push({0,src,0});
    dist[src] = 0;
    while(!q.empty()){
        auto it_s = q.front();
        int stop = it_s[0];
        int city = it_s[1];
        int cost = it_s[2];
        q.pop();
        if(stop >k && city != dst)
            continue;
        for(auto it : adj[city]){
            int city_r = it.first;
            int cost_r = it.second;
            if(cost + cost_r < dist[city_r]){
                dist[city_r] = cost + cost_r;
                q.push({stop+1,city_r,dist[city_r]});
            }
        }
    }
    if(dist[dst] != 1e9)
        cout<<dist[dst]<<endl;
    else
        cout<<-1<<endl;
}