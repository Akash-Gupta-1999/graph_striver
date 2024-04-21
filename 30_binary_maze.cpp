#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> grid = {{1,1,1,1},{1,1,0,1},{1,1,1,1},{1,1,0,0},{1,0,0,1}};
    pair<int,int> source = {0,1},dest = {2,3};
    vector<vector<int>> dist(grid.size(),vector<int>(grid[0].size(),1e9));
    dist[source.first][source.second] = 0;
    queue<vector<int>> q;
    q.push({source.first,source.second,0});
    vector<int> x = {-1,0,0,1};
    vector<int> y = {0,-1,1,0};
    while(!q.empty()){
        vector<int> temp = q.front();
        int i = temp[0];
        int j = temp[1];
        int d = temp[2];
        q.pop();
        for(int k=0;k<x.size();k++){
            int x_n = i + x[k];
            int y_n = j + y[k];
            if(x_n>=0 && y_n>=0 && x_n<grid.size() && y_n<grid[0].size()){
                if(grid[x_n][y_n] == 1 && (d + 1 < dist[x_n][y_n])){
                    dist[x_n][y_n] = d + 1;
                    q.push({x_n,y_n,dist[x_n][y_n]});
                }
            }
        }
    }
    if(dist[dest.first][dest.second] != 1e9)
        cout<<dist[dest.first][dest.second]<<endl;
    else
        cout<<"-1"<<endl;
}