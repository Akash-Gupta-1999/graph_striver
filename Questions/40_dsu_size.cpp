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

int main(){
    dsu p(7);
    p.unionbysize(1,2);
    p.unionbysize(2,3);
    p.unionbysize(4,5);
    p.unionbysize(6,7);
    p.unionbysize(5,6);
    if(p.findpar(3) == p.findpar(7))
        cout<<"same"<<endl;
    else    
        cout<<"not same"<<endl;
    p.unionbysize(3,7);
    if(p.findpar(3) == p.findpar(7))
        cout<<"same"<<endl;
    else    
        cout<<"not same"<<endl;
}