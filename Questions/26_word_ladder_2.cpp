#include<bits/stdc++.h>
using namespace std;

int main(){
    string startword = "der",endword = "dfs";
    vector<string> dict = {"des","der","dfr","dgt","dfs"};
    unordered_set<string> wl(dict.begin(),dict.end());
    queue<vector<string>> q;
    vector<string> used;
    int l = 0;
    q.push({startword});
    used.push_back(startword);
    vector<vector<string>> ans;
    while(!q.empty()){
        vector<string> list = q.front();
        q.pop();
        if(l < list.size()){
            l++;
            for(auto it : used){
                wl.erase(it);
            }
        }
        string word = list.back();
        if(word == endword){
            ans.push_back(list);
            continue;
        }
        for(int i=0;i<startword.size();i++){
            char c = word[i];
            for(int j=0;j<26;j++){
                char temp = j + 'a';
                word[i] = temp;
                if(wl.find(word)!=wl.end()){
                    list.push_back(word);
                    q.push(list);
                    used.push_back(word);
                    list.pop_back();
                }
            }
            word[i] = c;
        }
    }
    for(int i=0;i<ans.size();i++){
        for(auto it : ans[i])
            cout<<it<<" ";
        cout<<endl;
    }
}