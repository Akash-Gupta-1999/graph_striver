#include<bits/stdc++.h>
using namespace std;

int main(){
    int v = 3,s = 2;
    vector<vector<int>> edges = {{0,1,5},{1,0,3},{1,2,-1},{2,0,1}};
    vector<int> dist(v,1e8);
    dist[s] = 0;
    for(int i=0;i<v;i++){
        for(int j = 0;j<edges.size();j++){
            int a = edges[j][0];
            int b = edges[j][1];
            int w = edges[j][2];
            if(dist[a]!=1e8 && dist[a]+w<dist[b]){
                dist[b] = dist[a]+w;
            }
        }
    }
    bool isneg = false;
    for(int j = 0;j<edges.size();j++){
        int a = edges[j][0];
        int b = edges[j][1];
        int w = edges[j][2];
        if(dist[a]!=1e8 && dist[a]+w<dist[b]){
            isneg = true;
            break;
        }
    }
    if(isneg){
        for(auto it : dist)
            it = -1;
    }
    for(auto it : dist)
        cout<<it<<" ";
    cout<<endl;
}