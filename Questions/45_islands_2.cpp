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

bool isvalid(int i_n,int j_n,int m,int n){
    return i_n>=0 && j_n>=0 && i_n<n && j_n<m;
}

int main(){
    int n = 4,m = 5;
    int k = 4;
    vector<vector<int>> operators = {{1,1},{0,1},{3,3},{3,4}};
    vector<vector<int>> sea(n,vector<int>(m,0));
    dsu ds(m * n);
    vector<vector<int>> visited(n,vector<int>(m,0));
    int c = 0;
    vector<int> ans;
    for(auto it : operators){
        int i = it[0];
        int j = it[1];
        if(visited[i][j] == 1){
            ans.push_back(c);
            continue;
        }
        sea[i][j] = 1;
        visited[i][j] = 1;
        c++;
        int x[] = {-1,0,0,1};
        int y[] = {0,-1,1,0};
        for(int k = 0;k<4;k++){
            int i_new = i + x[k];
            int j_new = j + y[k];
            if(isvalid(i_new,j_new,m,n)){
                if(sea[i_new][j_new] == 1){
                    int node = i*m + j;
                    int new_node = i_new*m + j_new;
                    if(ds.findpar(node) != ds.findpar(new_node)){
                        c--;
                        ds.unionbysize(node,new_node);
                    }
                }
            }
        }
        ans.push_back(c);
    }
    for(auto it : ans)
        cout<<it<<" ";
    cout<<endl;
}