#include<bits/stdc++.h>
using namespace std;

class dsu{
    public :
    vector<int> size,parent;
    dsu(int v){
        size.resize(v+1,1);
        parent.resize(v+1);
        for(int i=0;i<v;i++)
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


int main(){
    int n = 6;
    int m = 5;
    vector<vector<int>> edge = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    dsu ds(n);
    int extra = 0;
    for(int i=0;i<m;i++){
        int u = edge[i][0];
        int v = edge[i][1];
        if(ds.findpar(u) == ds.findpar(v)){
            extra++;
        }
        ds.unionbysize(u,v);
    }
    int prov = 0;
    for(int i=0;i<n;i++){
        if(ds.parent[i] == i){
            prov++;
        }
    }
    //cout<<prov<<" "<<extra<<endl;
    if(prov-1<=extra){
        cout<<prov-1<<endl;
    }
    else{
        cout<<"-1"<<endl;
    }
}