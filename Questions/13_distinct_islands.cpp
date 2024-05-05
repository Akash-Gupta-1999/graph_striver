#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>& sea,int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<sea[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> bfs(vector<vector<int>>& sea,vector<vector<int>>& visited,vector<int> x,vector<int> y,int i,int j){
    queue<pair<int,int>> q;
    vector<vector<int>> ans;
    q.push(make_pair(i,j));
    ans.push_back({0,0});
    while(q.empty() == false){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        if(visited[a][b] == 0 && sea[i][j] == 1){
            visited[a][b] = 1;
            for(int k=0;k<x.size();k++){
                int x1 = a+x[k];
                int x2 = b+y[k];
                if(x1 >= 0 && x2>=0 && x1<sea.size() && x2<sea[0].size())
                    if(sea[x1][x2] == 1 && visited[x1][x2] == 0){
                        q.push(make_pair(x1,x2));
                        ans.push_back({x1-i,x2-j});
                    }
            }
        }
    }
    return ans;
}

int main(){
    int m,n;
    cin>>m>>n;
    int temp;
    vector<vector<int>> sea(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>temp;
            sea[i][j] = temp;
        }
    }
    print(sea,m,n);
    vector<vector<int>> visited(m,vector<int>(n,0));
    vector<int> x = {-1,0,0,1};
    vector<int> y = {0,-1,1,0};
    int islands = 0;
    set<vector<vector<int>>> s;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j] == 0 && sea[i][j] == 1){
                vector<vector<int>>ans = bfs(sea,visited,x,y,i,j);
                s.insert(ans);
            }
        }
    }
    cout<<s.size()<<endl;
}