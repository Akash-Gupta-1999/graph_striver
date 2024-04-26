#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr ={2,5,7};
    int start = 3,end = 30;
    queue<pair<int,int>> q;
    q.push({0,start});
    vector<int> dist(100000,INT_MAX);
    dist[start] = 0;
    int mod = 100000;
    int ans = -1;
    while(!q.empty()){
        int step = q.front().first;
        int node = q.front().second;
        q.pop();
        if(node == end){
            ans = step;
            break;
        }
        for(auto it : arr){
            int num = (node * it) % mod;
            if(step + 1 < dist[num]){
                dist[num] = step + 1;
                q.push({step + 1, num});
            }
        }
    }
    cout<<ans<<endl;
}