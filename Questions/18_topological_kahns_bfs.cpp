#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> adj = {{},{},{4},{2},{1,2},{1,3}};
    vector<int> indegree(adj.size()+1,0);
    for(int i=0;i<adj.size();i++){
        for(int j=0;j<adj[i].size();j++){
            indegree[adj[i][j]]++;
        }
    }
    queue<int> q;
    vector<int> topo;
    for(int i=1;i<=adj.size();i++)
        if(indegree[i] == 0){
            q.push(i);
            topo.push_back(i);
        }   
    while(!q.empty()){
        int n = q.front();
        q.pop();
        for(int i=0;i<adj[n-1].size();i++){
            indegree[adj[n-1][i]]--;
            if(indegree[adj[n-1][i]] == 0){
                topo.push_back(adj[n-1][i]);
                q.push(adj[n-1][i]);
            }
        } 
    }
    for(auto it : topo)
        cout<<it-1<<" ";
    cout<<endl;
}