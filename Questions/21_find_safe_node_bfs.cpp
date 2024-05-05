#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> adj = {{1,2},{2,3},{5},{0},{5},{},{},{0}};
    vector<vector<int>> rev_adj(adj.size());
    for(int i=0;i<adj.size();i++){
        for(auto it : adj[i]){
            rev_adj[it].push_back(i);
        }
    }
    vector<int> indegree(adj.size(),0);
    for(int i=0;i<adj.size();i++){
        for(auto it : rev_adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    vector<int> ans;
    for(int i=0;i<adj.size();i++){
        if(indegree[i] == 0){
            q.push(i);
            ans.push_back(i);
        }  
    }
    while(!q.empty()){
        int n = q.front();
        q.pop();
        for(auto it : rev_adj[n]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
                ans.push_back(it);
            }
        }
    }
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
}