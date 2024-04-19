#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& adj,vector<int>& visited,vector<int>& path_visited,stack<int>& order,int node){
    visited[node] = 1;
    path_visited[node] = 1;
    for(auto it : adj[node]){
        if(visited[it] == 0){
            if(dfs(adj,visited,path_visited,order,it))
                return true;
        }
        else if(path_visited[it] == 1)
            return true;
    }
    order.push(node);
    path_visited[node] = 0;
    return false;
}

int main(){
    int n = 2,p = 2;
    vector<pair<int,int>> prerequisites = {{1,0},{0,1}}; 
    vector<vector<int>> adj(n);
    for(int i=0;i<p;i++){
        adj[prerequisites[i].second].push_back(prerequisites[i].first);
    }
    vector<int> visited(n,0);
    vector<int> path_visited(n,0);
    stack<int> order;
    bool iscycle = false;
    for(int i=0;i<n;i++){
        if(visited[i] == 0){
            if(dfs(adj,visited,path_visited,order,i)){
                iscycle = true;
                break;
            }
        }
    }
    if(iscycle)
        cout<<"There is no sequence exist"<<endl;
    else{
        while(!order.empty()){
            cout<<order.top()<<" ";
            order.pop();
        }
        cout<<endl;
    }
}