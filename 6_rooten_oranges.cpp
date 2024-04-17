#include<bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>>& oranges,queue<pair<int,int>> q){
    vector<int> x = {-1,0,0,1};
    vector<int> y = {0,-1,1,0};
    queue<pair<int,int>> iq;
    int seconds = 0;
    bool rotten = false;
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for(int k=0;k<x.size();k++){
            int x_c = a + x[k];
            int y_c = b + y[k];
            if(x_c >=0 && y_c>=0 && x_c<oranges.size() && y_c<oranges[0].size()){
                if(oranges[x_c][y_c] == 1){
                    iq.push(make_pair(x_c,y_c));
                    rotten = true;
                    oranges[x_c][y_c] = 2;
                }
            }
        }
        if(q.empty()){
            if(rotten)
                seconds++;
            while(!iq.empty()){
                q.push(iq.front());
                iq.pop();
            }
            rotten = false;
        }
    }
    return seconds;
}

int main(){
    vector<vector<int>> oranges = {{2,1,1},{1,1,0},{0,1,1}};
    queue<pair<int,int>> q;
    for(int i=0;i<oranges.size();i++){
        for(int j=0;j<oranges[0].size();j++){
            if(oranges[i][j] == 2){
                q.push(make_pair(i,j));
            }
        }
    }
    int seconds = bfs(oranges,q);
    for(int i=0;i<oranges.size();i++){
        for(int j=0;j<oranges[0].size();j++){
            if(oranges[i][j] == 1){
                seconds = -1;
                break;
            }
        }
    }
    cout<<seconds<<endl;
}