#include<bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>& adjlist,vector<int> visited,int n,int m,int node){
    queue<pair<int,int>> q;
    q.push(make_pair(node,1));
    visited[node] = 1;
    while(!q.empty()){
        int a = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int k=0;k<adjlist[a-1].size();k++){
            if(visited[adjlist[a-1][k]] == 0){
                if(c == 1){
                    q.push(make_pair(adjlist[a-1][k],2));
                    visited[adjlist[a-1][k]] = 2;
                }   
                else{
                    q.push(make_pair(adjlist[a-1][k],1));
                    visited[adjlist[a-1][k]] = 1;
                }  
            }
            else if(visited[adjlist[a-1][k]] == c)
                return false;
        }
    }
    return true;
}

bool dfs(vector<vector<int>>& adjlist,vector<int>& visited,int n,int m,int node,int c){
    visited[node] = c;
    for(int k=0;k<adjlist[node-1].size();k++){
        if(visited[adjlist[node-1][k]] == 0)
            if(c == 1){
                return dfs(adjlist,visited,n,m,adjlist[node-1][k],2);
            }   
            else{
                return dfs(adjlist,visited,n,m,adjlist[node-1][k],1);
            }   
        else if(visited[adjlist[node-1][k]] == c) 
            return false;
    }
    return true;
}

int main(){
    int m = 7, n= 7;
    vector<vector<int>> adjlist = {{2},{1,3,4},{2,6},{2,5},{4,6},{3,5,7},{6}};
    vector<int> visited(n+1,0);
    cout<<boolalpha<<bfs(adjlist,visited,n,m,1)<<endl;
    cout<<boolalpha<<dfs(adjlist,visited,n,m,1,1)<<endl;
}