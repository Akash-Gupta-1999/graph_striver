#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> grid = {{1,2,2},{3,8,2},{5,3,5}};
    vector<vector<int>> dist(grid.size(),vector<int>(grid[0].size(),1e9));
    dist[0][0] = 0;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
    q.push({0,0,0});
    vector<int> x = {-1,0,0,1};
    vector<int> y = {0,-1,1,0};
    while(!q.empty()){
        vector<int> temp = q.top();
        int d = temp[0];
        int i = temp[1];
        int j = temp[2];
        q.pop();
        for(int k=0;k<x.size();k++){
            int x_n = i + x[k];
            int y_n = j + y[k];
            if(x_n>=0 && y_n>=0 && x_n<grid.size() && y_n<grid[0].size()){
                int abs_diff = abs(grid[i][j] - grid[x_n][y_n]);
                abs_diff = max(abs_diff,dist[i][j]);
                if(abs_diff < dist[x_n][y_n]){
                    dist[x_n][y_n] = abs_diff;
                    q.push({abs_diff,x_n,y_n});
                }
            }
        }
    }
    cout<<dist[grid.size()-1][grid[0].size()-1]<<endl;
}