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

bool isvalid(int i,int j,int n){
    return i>=0 && j>=0 && i<n && j<n;
}

int main(){
    vector<vector<int>> grid = {{0,1,0,0},{1,0,1,1},{1,1,0,1},{0,0,0,1}};
    int n = grid.size();
    dsu ds(n*n);
    int x[] = {-1,0,0,1};
    int y[] = {0,-1,1,0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 1){
                for(int k=0;k<4;k++){
                    int i_n = i + x[k];
                    int j_n = j + y[k];
                    int node = i*n + j;
                    int n_node = i_n*n + j_n;
                    if(isvalid(i_n,j_n,n)){
                        if(grid[i_n][j_n] == 1)
                            ds.unionbysize(node,n_node);
                    }
                }
            }
        }
    }
    int m_size = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 0){
                unordered_set<int> s;
                int node = i*n + j;
                for(int k=0;k<4;k++){
                    int i_n = i + x[k];
                    int j_n = j + y[k];
                    int n_node = i_n*n + j_n;
                    if(isvalid(i_n,j_n,n)){
                        if(grid[i_n][j_n] == 1)
                            s.insert(ds.findpar(n_node));
                    }
                }
                int size = 0;
                for(auto it : s){
                    size+=ds.size[it];
                }
                m_size = max(m_size,size+1);
            }
        }
    }
    for(int i=0;i<n*n;i++){
        m_size = max(m_size,ds.size[ds.findpar(i)]);
    }
    cout<<m_size<<endl;
}