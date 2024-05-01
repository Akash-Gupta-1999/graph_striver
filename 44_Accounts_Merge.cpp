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
    int n = 5;
    vector<vector<string>> accounts = {{"Gabe","Gabe00@m.co","Gabe3@m.co","Gabe1@m.co"},{"Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"},{"Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"},{"Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"},{"Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"}};
    dsu ds(n);
    unordered_map<string,int> umap;
    for(int i=0;i<n;i++){
        for(int j=1;j<accounts[i].size();j++){
            if(umap.find(accounts[i][j]) == umap.end()){
                umap[accounts[i][j]] = i;
            }
            else{
                ds.unionbysize(i,umap[accounts[i][j]]);
            }
        }
    }
    vector<vector<string>> merged_acc(n);
    for(auto it : umap){
        string mail = it.first;
        int node = ds.findpar(it.second);
        merged_acc[node].push_back(mail);
    }
    vector<vector<string>> ans;
    for(int i=0;i<n;i++){
        if(merged_acc[i].size() == 0)
            continue;
        sort(merged_acc[i].begin(),merged_acc[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(auto it : merged_acc[i])
            temp.push_back(it);
        ans.push_back(temp);
    }
    for(auto it : ans){
        for(auto it1:it){
            cout<<it1<<" ";
        }
        cout<<endl;
    }
}