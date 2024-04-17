#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>& graph){
    for(int i=1;i<graph.size();i++){
        cout<<i<<" : ";
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

void traverse(vector<vector<int>>& graph,int n,int k){
    int visited[n+1] = {0};
    queue<int> v;
    v.push(k);
    while(v.empty() == false){
        int vertex = v.front();
        v.pop();
        if(visited[vertex] == 0){
            cout<<vertex<<" ";
            for(int i=0;i<graph[vertex].size();i++)
                v.push(graph[vertex][i]);
            visited[vertex] = 1;
        }
    }
    cout<<endl;
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> graph(n+1);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    print(graph);
    traverse(graph,n,2);
}