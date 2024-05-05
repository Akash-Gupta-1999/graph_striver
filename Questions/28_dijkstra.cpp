#include<bits/stdc++.h>
using namespace std;

int main(){
    int v = 6,s =0;
    vector<vector<pair<int,int>>> adj = {{{1,4},{2,4}},{{0,4},{2,2}},{{0,4},{1,2},{3,3},{5,6},{4,1}},{{2,3},{5,2}},{{2,1},{5,3}},{{3,2},{4,3},{2,6}}};
    set<pair<int,int>> st;
    vector<int> dist(v,1e9);
    dist[s] = 0;
    st.insert(make_pair(0,s));
    while(!st.empty()){
        int node = st.begin()->second;
        st.erase(st.begin());
        for(auto it : adj[node]){
            int w = it.second;
            int node_adj = it.first;
            if(dist[node] + w < dist[node_adj]){
                if(dist[node_adj]!=1e9){
                    st.erase(make_pair(dist[node_adj],node_adj));
                }
                dist[node_adj] = dist[node] + w;
                st.insert(make_pair(dist[node_adj],node_adj));
            }
        }
    }
    for(auto it : dist)
        cout<<it<<" ";
    cout<<endl;
}