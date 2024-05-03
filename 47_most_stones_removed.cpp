#include<bits/stdc++.h>
using namespace std;

class dsu{
    public :
    vector<int> size,parent;
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

int main(){
    int n = 10;
    vector<vector<int>> stones = {{33,41},{12,38},{7,45},{7,19},{28,30},{7,24},{2,34},{7,9},{4,9},{2,8}};
    int row = 0,col = 0;
    for(int i=0;i<n;i++){
        row = max(stones[i][0],row);
        col = max(stones[i][1],col);
    }
    dsu ds(row+col+1);
    unordered_map<int,int> stones_v;
    for(auto it : stones){
        int i = it[0];
        int j = it[1] + row + 1;
        ds.unionbysize(i,j);
        stones_v[i] = 1;
        stones_v[j] = 1;
    }
    int c = 0;
    for(auto it : stones_v){
        cout<<it.first<<" ";
        if(ds.findpar(it.first) == it.first)
            c++;
    }
    cout<<n - c<<endl;
}