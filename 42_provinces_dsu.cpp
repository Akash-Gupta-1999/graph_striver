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
    vector<vector<int>> adj_mat = {{1,0,1},{0,1,0},{1,0,1}};
    int v = adj_mat.size();
    dsu ds(v);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(adj_mat[i][j] == 1){
                ds.unionbysize(i,j);
            }
        }
    }
    int prov = 0;
    for(int i=0;i<v;i++){
        if(ds.parent[i] == i)
            prov++;
    }
    cout<<prov<<endl;
}   