#include<bits/stdc++.h>
using namespace std;

class dsu{
    vector<int> rank,parent;
    public :
    dsu(int v){
        rank.resize(v+1,0);
        parent.resize(v+1);
        for(int i=0;i<=v;i++)
            parent[i] = i;
    }
    int findpar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findpar(parent[node]);
    }
    void unionbyrank(int u,int v){
        int u_par = findpar(u);
        int v_par = findpar(v);
        if(u_par == v_par)
            return;
        if(rank[u_par] > rank[v_par]){
            parent[v_par] = u_par;
        }
        else if(rank[u_par]<rank[v_par]){
            parent[u_par] = v_par;
        }
        else{
            parent[v_par] = u_par;
            rank[u_par]++;
        }
    }
};

int main(){
    dsu p(7);
    p.unionbyrank(1,2);
    p.unionbyrank(2,3);
    p.unionbyrank(4,5);
    p.unionbyrank(6,7);
    p.unionbyrank(5,6);
    if(p.findpar(3) == p.findpar(7))
        cout<<"same"<<endl;
    else    
        cout<<"not same"<<endl;
    p.unionbyrank(3,7);
    if(p.findpar(3) == p.findpar(7))
        cout<<"same"<<endl;
    else    
        cout<<"not same"<<endl;
}