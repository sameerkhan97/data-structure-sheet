/* Question Link : https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/


A board of length m and width n is given, we need to break this board into m*n squares such that cost of breaking is minimum. cutting cost
 for each edge will be given for the board. In short, we need to choose such a sequence of cutting such that cost is minimized. 

Examples: 
 For above board optimal way to cut into square is:
 Total minimum cost in above case is 42. It is evaluated using following steps.

Initial Value : Total_cost = 0
Total_cost = Total_cost + edge_cost * total_pieces
Cost 4 Horizontal cut         Cost = 0 + 4*1 = 4
Cost 4 Vertical cut        Cost = 4 + 4*2 = 12
Cost 3 Vertical cut        Cost = 12 + 3*2 = 18
Cost 2 Horizontal cut        Cost = 18 + 2*3 = 24
Cost 2 Vertical cut        Cost = 24 + 2*3 = 30
Cost 1 Horizontal cut        Cost = 30 + 1*4 = 34
Cost 1 Vertical cut        Cost = 34 + 1*4 = 38
Cost 1 Vertical cut        Cost = 38 + 1*4 = 42     */
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--){
		int m,n;
		cin>>m;
		cin>>n;	
		m--;
		n--;
		int x[m],y[n];
		for(int i=0;i<m;i++)	cin>>x[i];
		for(int i=0;i<n;i++)	cin>>y[i];
		sort(x,x+m,greater<int>());
		sort(y,y+n,greater<int>());
		int answer=0;
		int verticalCount=1,horizontalCount=1;
		int i=0,j=0;
		while(i<m && j<n){
			if(x[i]>y[j]){
				answer=answer+(x[i]*verticalCount);
				horizontalCount++;
				i++;
			}
			else{
				answer=answer+(y[j]*horizontalCount);
				verticalCount++;
				j++;
			}
		}
		while(i<m){
				answer=answer+(x[i]*verticalCount);
				i++;
		}
		while(j<n){
				answer=answer+(y[j]*horizontalCount);
				j++;
		}
		cout<<answer<<endl;
	}
	return 0;
}