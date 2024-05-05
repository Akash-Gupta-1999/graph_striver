#include<bits/stdc++.h>
using namespace std;

int main(){
    string startword = "toon",endword = "plea";
    vector<string> dict = {"poon","plee","same","poie","plea","plie","poin"};
    unordered_set<string> d(dict.begin(),dict.end());
    queue<pair<string,int>> q;
    q.push(make_pair(startword,1));
    bool isfind = false;
    d.erase(startword);
    while(!q.empty()){
        string word = q.front().first;
        int seq = q.front().second;
        q.pop();
        if(word == endword){
            isfind = true;
            cout<<"found : "<<seq<<endl;
            break;
        }
        for(int i=0;i<word.size();i++){
            for(int j=0;j<26;j++){
                string comp = word;
                char temp = j + 'a';
                comp[i] = temp;
                if(d.find(comp)!=d.end()){
                    q.push(make_pair(comp,seq+1));
                    d.erase(comp);
                }
            }
        }
    }
    if(!isfind)
        cout<<"Not Found"<<endl;
}