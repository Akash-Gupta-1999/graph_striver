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

void print(vector<vector<int>>& graph){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" : ";
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n = 5,k=4;
    vector<string> dict = {"baa","abcd","abca","cab","cad"};
    vector<vector<int>> adj(k);
    for(int i=1;i<n;i++){
        int j=0;
        bool flag = true;
        while(dict[i][j] == dict[i-1][j]){
            j++;
            if(j>=dict[i-1].size() || j>=dict[i].size()){
                flag = false;
                break;
            }
        }
        if(flag == false)
            continue;
        int first = dict[i-1][j] - 'a';
        int second = dict[i][j] - 'a';
        adj[first].push_back(second);
    }
    print(adj);
    vector<int> visited(k,0);
    vector<int> path_visited(k,0);
    stack<int> order;
    bool iscycle = false;
    for(int i=0;i<adj.size();i++){
        if(visited[i] == 0){
            if(dfs(adj,visited,path_visited,order,i)){
                iscycle = true;
                break;
            }
        }
    }
    if(iscycle)
        cout<<"Invalid Dictionary"<<endl;
    else{
        while(!order.empty()){
            char temp = order.top() + 'a';
            cout<<temp<<" ";
            order.pop();
        }
        cout<<endl;
    }
}