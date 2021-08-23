#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int v,e;
	cin>>v>>e;
	vector<int> g[v+1];
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
 
	for(int i=1;i<=v;i++){
		cout<<i<<"-->";
		for(int j=0;j<g[i].size();j++)
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
1-->2 5 
2-->1 3 
3-->2 4 6 
4-->3 
5-->1 
6-->3   */