#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>& grid){
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

void dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,vector<int> x,vector<int> y,int i,int j){
    visited[i][j] = 1;
    for(int k=0;k<x.size();k++){
        int i_new = i+x[k];
        int j_new = j+y[k];
        if(i_new>=0 && j_new>=0 && i_new<grid.size() && j_new<grid[0].size()){
            if(grid[i_new][j_new] == 0 && visited[i_new][j_new] == 0)
                dfs(grid,visited,x,y,i_new,j_new);
        }
    }
}

int main(){
    vector<vector<int>> grid = {{1,1,1,1},{1,0,0,1},{1,0,1,1},{1,1,0,0}};
    vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
    print(grid);
    vector<int> x = {-1,0,0,1};
    vector<int> y = {0,-1,1,0};
    for(int i=0;i<grid[0].size();i++){
        if(grid[0][i] == 0 && visited[0][i] == 0)
            dfs(grid,visited,x,y,0,i);
        if(grid[grid.size()-1][i] == 0 && visited[grid.size()-1][i] == 0)
            dfs(grid,visited,x,y,grid.size()-1,i);
    }
    for(int i=0;i<grid.size();i++){
        if(grid[i][grid[0].size()-1] == 0 && visited[i][grid[0].size()-1] == 0)
            dfs(grid,visited,x,y,i,grid[0].size()-1);
        if(grid[i][0] == 0 && visited[i][0] == 0)
            dfs(grid,visited,x,y,i,0);
    }
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j] == 0 && visited[i][j] == 0)
                grid[i][j] = 1;
        }
    }
    print(grid);
}