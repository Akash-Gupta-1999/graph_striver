#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_set<string> wl_dfs,unordered_map<string,int>& mpp,string word,string startword,vector<vector<string>>& ans,vector<string> seq){
    seq.push_back(word);
    wl_dfs.erase(word);
    if(word == startword){
        reverse(seq.begin(),seq.end());
        ans.push_back(seq);
        return;
    }
    for(int i=0;i<startword.size();i++){
        char c = word[i];
        string t = word;
        for(int j=0;j<26;j++){
            char temp = j + 'a';
            word[i] = temp;
            if(wl_dfs.find(word)!=wl_dfs.end() && mpp[word] < mpp[t]){
                dfs(wl_dfs,mpp,word,startword,ans,seq);
            }
        }
        word[i] = c;
    }
}

int main(){
    string startword = "dfs",endword = "der";
    vector<string> dict = {"dfs","des","dfd","der","dfr"};
    unordered_set<string> wl(dict.begin(),dict.end());
    unordered_set<string> wl_dfs = wl;
    queue<pair<string,int>> q;
    unordered_map<string,int> mpp;
    q.push(make_pair(startword,1));
    mpp[startword] = 1;
    wl.erase(startword);
    int s;
    while(!q.empty()){
        string word = q.front().first;
        int seq = q.front().second;
        q.pop();
        if(word == endword){
            s = seq;
            break;
        }
        for(int i=0;i<startword.size();i++){
            char c = word[i];
            for(int j=0;j<26;j++){
                char temp = j + 'a';
                word[i] = temp;
                if(wl.find(word)!=wl.end()){
                    wl.erase(word);
                    q.push(make_pair(word,seq+1));
                    mpp[word] = seq+1;
                }
            }
            word[i] = c;
        }
    }
    vector<vector<string>> ans;
    vector<string> seq;
    dfs(wl_dfs,mpp,endword,startword,ans,seq);
    for(auto it : ans){
        for(auto it1 : it)
            cout<<it1<<" ";
        cout<<endl;
    }
}