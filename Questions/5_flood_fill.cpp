#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& pixels,vector<vector<int>>& visited,int i,int j,int c){
    queue<pair<int,int>> q;
    vector<int> x = {-1,0,0,1};
    vector<int> y = {0,-1,1,0};
    q.push(make_pair(i,j));
    int t = pixels[i][j];
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        if(visited[a][b] == 0){
            pixels[a][b] = c;
        visited[a][b] = 1;
        for(int k=0;k<x.size();k++){
            int x_c = a+x[k];
            int y_c = b+y[k];
            if(x_c>=0 && y_c>=0 && x_c<pixels.size() && y_c<pixels[0].size())
                if(pixels[x_c][y_c] == t && visited[x_c][y_c] == 0)
                    q.push(make_pair(x_c,y_c));
        }
        }
    }
}

void print(vector<vector<int>>& pixels){
    for(int i=0;i<pixels.size();i++){
        for(int j=0;j<pixels[0].size();j++)
            cout<<pixels[i][j]<<" ";
        cout<<endl;
    }
}

int main(){
    vector<vector<int>> pixels = {{1,1,1},{1,1,0},{1,0,1}};
    int i,j,c;
    cin>>i>>j>>c;
    vector<vector<int>> visited(pixels.size(),vector<int>(pixels[0].size(),0));
    print(pixels);
    bfs(pixels,visited,i,j,c);
    print(pixels);
}