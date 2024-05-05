#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> adj = {{2},{3},{4,5},{2},{}};
    vector<int> indegree(adj.size()+1,0);
    for(int i=0;i<adj.size();i++){
        for(int j=0;j<adj[i].size();j++){
            indegree[adj[i][j]]++;
        }
    }
    queue<int> q;
    int c = 0;
    for(int i=1;i<=adj.size();i++)
        if(indegree[i] == 0){
            q.push(i);
        }   
    while(!q.empty()){
        int n = q.front();
        q.pop();
        c++;
        for(int i=0;i<adj[n-1].size();i++){
            indegree[adj[n-1][i]]--;
            if(indegree[adj[n-1][i]] == 0){
                q.push(adj[n-1][i]);
            }
        } 
    }
    if(c != adj.size())
        cout<<"cyclic"<<endl;
    else
        cout<<"acyclic"<<endl;
}