#include <bits/stdc++.h>
using namespace std;

int main() {
	int v,e;
	cin>>v>>e;
	int g[v+1][v+1];
	for(int i=1;i<v+1;i++){
		for(int j=1;j<v+1;j++)
			g[i][j]=0;
	}
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		g[x][y]=1;
		g[y][x]=1;
	}
	
	for(int i=1;i<v+1;i++){
		cout<<i<<"-->";
		for(int j=1;j<v+1;j++)
			cout<<g[i][j]<<" ";
		cout<<"\n";
	}
}


/*
stdin : 
6 5 
1 2 
1 5
2 3
3 4 
3 6

stdout : 
1-->0 1 0 0 1 0 
2-->1 0 1 0 0 0 
3-->0 1 0 1 0 1 
4-->0 0 1 0 0 0 
5-->1 0 0 0 0 0 
6-->0 0 1 0 0 0

*/