#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>& matrix){
    int v = matrix.size();
    for(int i=0;i<v;i++){
	    for(int j=0;j<v;j++){
	        cout<<matrix[i][j]<<" ";
	    }
        cout<<endl;
	}
}

int main(){
    vector<vector<int>> matrix = {{0,1,43},{1,0,6},{-1,-1,0}};
    print(matrix);
    int v = matrix.size();
	for(int i=0;i<v;i++){
	    for(int j=0;j<v;j++){
	        if(matrix[i][j] == -1)
	            matrix[i][j] = 1e9;
	    }
	}
	for(int k=0;k<v;k++){
	    for(int i=0;i<v;i++){
	        for(int j=0;j<v;j++){
	            matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	        }
	    }
	}
	for(int i=0;i<v;i++){
	    for(int j=0;j<v;j++){
	        if(matrix[i][j] == 1e9)
	            matrix[i][j] = -1;
	    }
	}
    print(matrix);
}