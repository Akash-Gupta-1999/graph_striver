#include<bits/stdc++.h>
using namespace std;

class dsu{
    vector<int> size,parent;
    public :
    dsu(int v){
        size.resize(v+1,1);
        parent.resize(v+1);
        for(int i=0;i<=v;i++)
            parent[i] = i;
    }
    int findpar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findpar(parent[node]);
    }
    void unionbysize(int u,int v){
        int u_par = findpar(u);
        int v_par = findpar(v);
        if(u_par == v_par)
            return;
        if(size[u_par]>size[v_par]){
            parent[v_par] = u_par;
            size[u_par]+=size[v_par];
        }
        else{
            parent[u_par] = v_par;
            size[v_par]+=size[u_par];
        }
    }
};

bool comparator(vector<int> a,vector<int> b){
    int i = 0;
    while(a[i]==b[i] && i<a.size())
        i++;
    return a[i]<b[i];
}

int main(){
    int n = 3,m =3;
    vector<vector<int>> edges = {{0,1,5},{1,2,3},{0,2,1}};
    vector<vector<int>> kru_edges;
    for(int i=0;i<m;i++){
        int u = edges[i][1];
        int v = edges[i][0];
        int w = edges[i][2];
        kru_edges.push_back({w,u,v});
        kru_edges.push_back({w,v,u});
    }
    int cost = 0;
    sort(kru_edges.begin(),kru_edges.end(),comparator);
    dsu p(n);
    for(int i=0;i<kru_edges.size();i++){
        int u = kru_edges[i][1];
        int v = kru_edges[i][2];
        int w = kru_edges[i][0];
        if(p.findpar(u) != p.findpar(v)){
            cost+=w;
            p.unionbysize(u,v);
        }
    }
    cout<<cost<<endl;
}