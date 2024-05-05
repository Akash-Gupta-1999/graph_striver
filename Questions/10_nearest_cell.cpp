#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& grid,vector<vector<int>>& visited,queue<pair<int,int>>& q){
    vector<int> x = {-1,0,0,1};
    vector<int> y = {0,-1,1,0};
    while(!q.empty()){
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for(int k=0;k<x.size();k++){
            int i_new = i + x[k];
            int j_new = j+y[k];
            if(i_new>=0 && j_new>=0 && i_new<grid.size() && j_new<grid[0].size()){
                if(grid[i_new][j_new] == 0 && visited[i_new][j_new] == 0){
                    grid[i_new][j_new] = grid[i][j] + 1;
                    q.push(make_pair(i_new,j_new));
                }
            }
        }
        grid[i][j]--;
        visited[i][j] = 1;
    }
}

void print(vector<vector<int>>& grid){
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> grid = {{1,0,1},{1,1,0},{1,0,0}};
    vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
    queue<pair<int,int>> q;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j] == 1)
                q.push(make_pair(i,j));
        }
    }
    print(grid);
    bfs(grid,visited,q);
    print(grid);
}